// 7-28 搜索树判断 （25 point(s)）
// 对于二叉搜索树，我们规定任一结点的左子树仅包含严格小于该结点的键值，而其右子树包含大于或等于该结点的键值。如果我们交换每个节点的左子树和右子树，得到的树叫做镜像二叉搜索树。
// 现在我们给出一个整数键值序列，请编写程序判断该序列是否为某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，如果是，则输出对应二叉树的后序遍历序列。
//
// 输入格式:
// 输入的第一行包含一个正整数N（≤1000），第二行包含N个整数，为给出的整数键值序列，数字间以空格分隔。

// 输出格式:
// 输出的第一行首先给出判断结果，如果输入的序列是某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，则输出YES，否侧输出NO。如果判断结果是YES，下一行输出对应二叉树的后序遍历序列。数字间以空格分隔，但行尾不能有多余的空格。

// 输入样例1:
// 7
// 8 6 5 7 10 8 11
// 输出样例1:
// YES
// 5 7 6 8 11 10 8
//
// 输入样例2:
// 7
// 8 6 8 5 10 9 11
// 输出样例2:
// NO


// 解题思路：1.首先是判断是否是二叉搜索树，给出先序遍历，因而先序的第一个数字是根结点，
          // 找到第一个大于等于根节点的数字，从这个数字开始为右子树，若右子树中有小于根结点的数
          // 那么它不是二叉搜索树；  镜像结点判断条件相反即可
             // 2、倘若是二叉搜索树则一边递归一边生成二叉树，最后返回根节点
        // 3、对二叉搜索树进行后序遍历

#include <iostream>
#include <vector>

bool is_bst_less(const std::vector<int>& arr) {
  int root = arr[0];
  int ind;
  for (ind=1; ind!=arr.size(); ++ind) {
    if (arr[ind] >= root) {
      break;
    }
  }
  
  for (int i=ind; i!=arr.size(); ++i) {
    if (arr[i] < root) {
      return false;
    }
  }

  return true;
}

bool is_bst_greater(const std::vector<int>& arr) {
  int root = arr[0];
  int ind;
  for (ind=1; ind!=arr.size(); ++ind) {
    if (arr[ind] <= root) {
      break;
    }
  }
  
  for (int i=ind; i!=arr.size(); ++i) {
    if (arr[i] > root) {
      return false;
    }
  }

  return true;
}



int main(int argc, char* argv[]) {
  int N;
  std::cin >> N;

  std::vector<int> arr(N);
  for (int i=0; i!=N; ++i) {
    std::cin >> arr[i];
  }

  std::cout << (is_bst_less(arr) || is_bst_greater(arr)) << std::endl;

  return 0;
}
