/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<RandomListNode*, RandomListNode*> tab;
        for (RandomListNode *cur = head; cur; cur=cur->next) {
            RandomListNode *mirror = new RandomListNode(cur->label);
            tab[cur] = mirror;
        }
        
        for (RandomListNode *cur = head; cur; cur=cur->next) {
            RandomListNode *mirror = tab[cur];
            mirror->random = tab[cur->random];
            mirror->next = tab[cur->next];
        }
        
        return tab[head];
    }
};

