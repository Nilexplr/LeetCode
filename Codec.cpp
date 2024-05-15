#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> qe;
        TreeNode* actual_node;
        string result = "[";
        string null_str = "";

        if (root == NULL)
            return "[]";

        result.append(to_string(root->val));
        qe.push(root->left);
        qe.push(root->right);

        while (!qe.empty()) {
            actual_node = qe.front();
            qe.pop();
            if (actual_node) {
                if (!null_str.empty()) {
                    result.append(null_str);
                    null_str.clear();
                }
                result.append(","+to_string(actual_node->val));
            }
            else {
                null_str.append(",null");
                continue;
            }
            qe.push(actual_node->left);
            qe.push(actual_node->right);
        }
        result.append("]");
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int value;
        queue<TreeNode*> qe;
        TreeNode *root;
        TreeNode *next_node;
        TreeNode *actual_node;
        std::string content = data.substr(1, data.length() - 2);
        if (content == "")
            return NULL;
        istringstream iss(content);
        string token;

        getline(iss, token, ',');

        root = new TreeNode(stoi(token));
        qe.push(root);

        while (!qe.empty()) {
            actual_node = qe.front();
            qe.pop();
            
            if (!getline(iss, token, ','))
                break;
            if (token != "null") {
                value = stoi(token);
                next_node = new TreeNode(value);
                actual_node->left = next_node;
                qe.push(next_node);
            }
            if (!getline(iss, token, ','))
                break;
            if (token != "null") {    
                value = stoi(token);
                next_node = new TreeNode(value);
                actual_node->right = next_node;
                qe.push(next_node);
            }
        }
        return root;
    }
};

// int main() 
// {
//     TreeNode one = TreeNode(1);
//     TreeNode two = TreeNode(2);
//     TreeNode three = TreeNode(3);
//     TreeNode four = TreeNode(4);
//     TreeNode five = TreeNode(5);
//     Codec cd;

//     one.left = &two;
//     one.right = &three;
//     three.left = &four;
//     three.right = &five;
//     cout << cd.deserialize("[1,2,3,null,null,4,5]") << endl;

// }