#include <cstdlib>
#define debug

#ifdef debug
#include <fstream>
static const constexpr char* test_fdata = "in.txt";
#endif

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <unordered_set>
#include <utility>

struct TreeNode {
    using ptr_t = std::shared_ptr<TreeNode>;

    TreeNode(const std::string& idata) : data(idata) {}

    ptr_t left;
    ptr_t right;
    const std::string data;
};

using Node = TreeNode::ptr_t;
using Tree = TreeNode::ptr_t;

Tree constructs_tree_from_stream(std::istream& is);
bool is_isomorphism(Tree lhs, Tree rhs);

int main() {
#ifdef debug
    std::ifstream fin{test_fdata};
    std::cin.rdbuf(fin.rdbuf());
#endif

    Tree T1 = constructs_tree_from_stream(std::cin);
    Tree T2 = constructs_tree_from_stream(std::cin);

    if (is_isomorphism(T1, T2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

size_t finds_root(size_t line_num, const std::vector<int>& lhs, const std::vector<int>& rhs) {          
    std::unordered_set<int> set(lhs.begin(), lhs.end());                                                
    std::copy(rhs.begin(), rhs.end(), std::inserter(set, set.begin()));                                 
    for (size_t i = 0; i != line_num; ++i) {                                                                                                                           
        auto find_set = set.find(i);                                                                    
        if (find_set == set.end()) {                                                                    
            return i;                                                                                   
        }                                                                                               
    }                                                                                                   
}  

Tree constructs_tree_from_stream(std::istream& is) {
    size_t line_num;
    is >> line_num;
    if (line_num == 0) {
      return nullptr;
    }

    std::vector<TreeNode::ptr_t> v_node;
    std::vector<int> v_left, v_right;
    v_node.reserve(line_num); v_left.reserve(line_num); v_right.reserve(line_num);

    for (size_t i = 0; i != line_num; ++i) {
        std::string data, left, right;
        std::getline(std::getline(std::getline(is, data, ' '), left, ' '), right);
        data.erase(0, data.find_first_not_of("\n"));
        v_node.emplace_back(std::make_shared<TreeNode>(data));
        v_left.emplace_back(left == "-" ? -1 : std::atoi(left.c_str()));
        v_right.emplace_back(right == "-" ? -1 : std::atoi(right.c_str()));
    }

    for (size_t i = 0; i != line_num; ++i) {
        if (v_left[i] != -1) {
            v_node[i]->left = v_node[v_left[i]];
        }
        if (v_right[i] != -1) {
            v_node[i]->right= v_node[v_right[i]];
        }
    }
    
    return v_node[finds_root(line_num, v_left, v_right)];
}

bool is_isomorphism(Tree lhs, Tree rhs) {
    if (lhs == nullptr and rhs == nullptr) {
        return true;
    } else if ((lhs == nullptr and rhs != nullptr) or (lhs != nullptr and rhs == nullptr)) {
        return false;
    } else if (lhs->data != rhs->data) {
        return false;
    } else {  // lhs->data == rhs->data holds, comparing children
        return (is_isomorphism(lhs->left, rhs->left) and is_isomorphism(lhs->right, rhs->right)) or
               (is_isomorphism(lhs->left, rhs->right) and is_isomorphism(lhs->right, rhs->left));
    }
}