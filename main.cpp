/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode* root,*temp;
    root=NULL;
    for(int i=0;i<preorderSize;i++)
    {
        temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val=preorder[i];
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
           struct TreeNode* curr,*ptr;
            curr=root;
            while(curr)
            {
                ptr=curr;;
                if(curr->val > temp->val)
                {
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
            if(temp->val > ptr->val)
            {
                ptr->right=temp;
            }
            else
            {
                ptr->left=temp;
            }
        }
    }
    return root;
}
