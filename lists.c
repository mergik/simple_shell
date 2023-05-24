#include "main.h"

/**
 * addNodeList - adds a new node at the beginning of list.
 * @head: Pointer to the start of the list
 * @str: The key for the new node.
 * @value: The value for the new node.
 * Return: Pointer to the new head of the list
 */
list_n *addNodeList(list_n **head, char *str, char *value)
{
    list_n *node = malloc(sizeof(list_n));
    if (node == NULL)
        return NULL;
    
    node->string = _strdup(str);
    node->length = _strlen(node->string);
    node->value = _strdup(value);
    node->valueLength = _strlen(value);
    node->nextNode = *head;
    *head = node;

return node;
}

list_n *getNodeList(list_n *head, char *str)
{
    list_n *current = head;
    while (current != NULL)
    {
        if (!_strcmp(current->string, str))
            break;
        current = current->nextNode;
    }

return current;

}