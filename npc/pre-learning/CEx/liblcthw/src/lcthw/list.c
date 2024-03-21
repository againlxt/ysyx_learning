#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    check(list != NULL, "Failed to destory list");
    LIST_FOREACH(list, first, next, cur)

    free(list->last);
    free(list);

error:

}


void List_clear(List *list)
{
    check(list != NULL, "Failed to clear list");
    LIST_FOREACH(list, first, next, cur)

error:
}


void List_clear_destroy(List *list)
{
    List_clear(list);
    List_destroy(list);
}


void List_push(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    check(value != NULL, "Failed to push list, value is NULL");
    node->value = value;

    check(list != NULL, "Failed to push list");
    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
}

void *List_pop(List *list)
{
    check(list != NULL, "Failed to pop list");
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;

error:
}

void List_unshift(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    check(value != NULL, "Failed to unshift list, value is NULL");
    node->value = value;

    check(list != NULL, "Failed to unshift list");
    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
}

void *List_shift(List *list)
{
    check(list != NULL, "Failed to shift list");
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;

error:
}

void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node can't be NULL");

    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}

List* List_copy(List *list) {
    List *result_list;
    check(list != NULL, "Failed to copy list, list is NULL");
    ListNode *node = list->first;
    result_list = List_create();

    for (size_t i = 0; i < list->count; i++)
    {
        List_unshift(result_list, node->value);
        node = node->next;
    }

    return result_list;
    
error:
    return;
}

int List_eqa(List *a, List *b) {
    check(a != NULL, "Failed to eqa, a is NULL");
    check(b != NULL, "Failed to eqa, b is NULL");
    ListNode *nodea = calloc(1, sizeof(ListNode));
    ListNode *nodeb = calloc(1, sizeof(ListNode));
    check_mem(nodea);
    check_mem(nodeb);

    nodea = a->first;
    nodeb = b->first;
    if (nodea == nodeb == NULL)
    {
        return 1;
    }
    else if (nodea == NULL || nodeb == NULL)
    {
        return 0;
    }
    else if (a->count != b->count)
    {
        return 0;
    }
    else {
        for (size_t i = 0; i < a->count; i++)
        {
            if (nodea->value != nodeb->value)
            {
                return 0;
            }
            nodea = nodea->next;
            nodeb = nodeb->next;
        }
        return 1;
    }
error:
    return 0;
}