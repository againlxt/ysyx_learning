#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
};

struct Database *db;

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database.");
}

// 创建对印文件名的文件流
struct Connection *Database_open(const char *filename, char mode)
{
    // 在堆上申请Connection结构体conn的内存
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    // 在堆上申请数据库的内存
    db = malloc(sizeof(struct Database));
    if(!db) die("Memory error");

    // 创建文件流
    // 模式为c时将文件流创建为写入流
    // 其他模式则为读取流
    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(db) free(db);
        free(conn);
    }
}

// 将数据库写入对印文件
void Database_write(struct Connection *conn)
{
    // 重定向流
    rewind(conn->file);

    int rc = fwrite(db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    // 刷新输出缓冲区
    // 清除输入缓冲区
    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        db->rows[i] = addr;
    }
}

// 设置数据
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &db->rows[id];
    // 判断对应地址是否已经设置数据
    if(addr->set) die("Already set, delete it first");

    // 该地址已被设置数据
    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    addr->name[511] = '\0';
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed");
}

// 获取对印id的数据
void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(id >= MAX_ROWS) die("There's not that many records.");

    switch(action) {
        // 先初始化数据库，再初始化数据 
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        // 获取对印id的数据
        case 'g':
            if(argc != 4) die("Need an id to get");

            Database_get(conn, id);
            break;

        // 将特定数据输入数据库
        case 's':
            if(argc != 6) die("Need id, name, email to set");
            
            // 设置写入流数据
            Database_set(conn, id, argv[4], argv[5]);
            // 写入
            Database_write(conn);
            break;
        
        // 删除对应id的数据
        case 'd':
            if(argc != 4) die("Need id to delete");
            // 删除
            Database_delete(conn, id);
            // 初始化
            Database_write(conn);
            break;

        // 遍历数据库
        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}

