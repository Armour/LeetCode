/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *buildTree(struct ListNode *st, struct ListNode *ed) {
    if (st == ed) return NULL;
    struct ListNode *slow = st;
    struct ListNode *fast = st;
    while (fast && fast->next != ed && fast->next->next != ed) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->val = slow->val;
    newNode->left = buildTree(st, slow);
    newNode->right = buildTree(slow->next, ed);
    return newNode;
}

struct TreeNode *sortedListToBST(struct ListNode* head) {
    return buildTree(head, NULL);
}
