/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
       int index =0;
       vector<string> splitString(string s , char delimeter)
       {
        vector<string>result;
        stringstream mystream(s);
       string token ="";
        while(getline(mystream , token , delimeter))
        {
            result.push_back(token);
        }
        return result ;
       }
    void dfs(TreeNode* root , string& data){
        if(root==nullptr){
            data+="N|"; 
            return;
        }
        data+= (to_string(root->val)+"|");
        dfs(root->left , data);
        dfs(root->right , data);
        return ;
    }
    void dfsDe(TreeNode* root , vector<string>&data){
            if(index>=data.size()||root==nullptr){
                return ;
            }
            if(data[index]=="N"){
                root->left = nullptr;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(data[index]));
                root->left = leftNode;
            }
            index++;
            dfsDe(root->left , data);
            if(data[index]=="N"){
                root->right = nullptr;
            }else {
                TreeNode* rightNode = new TreeNode(stoi(data[index]));
                root->right = rightNode;
            }
            index++;
            dfsDe(root->right , data);
       return;
    }
    string serialize(TreeNode* root) {
        string data ="";
        dfs(root , data);
     return data;
    }

  
    TreeNode* deserialize(string data) {
     vector<string>split = splitString(data , '|');
     index = 0;
     if(split[0]=="N"){return nullptr;}
       TreeNode* root = new TreeNode(stoi(split[0]));
       index++;
       dfsDe(root , split);
      return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));