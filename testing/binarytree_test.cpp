/**
 * Here is a Binary Expression Tree for Boolean expressions
 * Just a simple example
 */

#include <exception>
#include <iostream>
#include <memory>  // smart pointer
#include <queue>
#include <stack>
#include <vector>

class Node {
   public:
    Node(char const& _e) : element(_e), left(nullptr), right(nullptr) {}
    Node(char const& _e, std::unique_ptr<Node>& _l, std::unique_ptr<Node>& _r)
        : element(_e) {
        left = std::move(_l);
        right = std::move(_r);
    }

   public:
    char element;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

class BinaryExpressTree {
   public:
    // bottom-up method to construct the binary tree
    BinaryExpressTree(std::vector<char>& elements) {
        std::stack<std::unique_ptr<Node>> temps;
        std::stack<bool> results;
        for (auto& it : elements) {
            if (it == '1' || it == '0') {
                temps.push(std::make_unique<Node>(it));

                results.push((it == '1') ? true : false);
            } else if (it == '&' || it == '|') {
                if (temps.size() < 2 || results.size() < 2)
                    throw std::length_error("stack size error");

                // std::cout << "stk size:" << temps.size() << std::endl;
                std::unique_ptr<Node> r = std::move(temps.top());
                temps.pop();
                // std::cout << "stk size:" << temps.size() << std::endl;
                std::unique_ptr<Node> l = std::move(temps.top());
                temps.pop();
                std::unique_ptr<Node> cur_node =
                    std::make_unique<Node>(it, l, r);

                temps.push(std::move(cur_node));

                bool tmp1 = results.top();
                results.pop();
                bool tmp2 = results.top();
                results.pop();
                (it == '&') ? results.push((tmp1 && tmp2))
                            : results.push((tmp1 || tmp2));
            } else
                throw std::invalid_argument("invalid element:" + it);
        }

        root_ = std::move(temps.top());
        result_ = results.top();
    }

    void showExpression() {
        std::queue<char> output;
        inorder(root_, output);

        while (output.size() > 0) {
            std::cout << output.front();
            output.pop();
        }
        std::cout << std::endl;
    }

    bool solve() { return dfs(root_); }

    void test() {
        if (solve() == result_)
            std::cout << "success" << std::endl;
        else
            std::cout << "fail" << std::endl;
    }

    ~BinaryExpressTree() {}

   private:
    void inorder(std::unique_ptr<Node>& node, std::queue<char>& expression) {
        if (node == nullptr) return;

        if (node->left) expression.push('(');

        inorder(node->left, expression);

        expression.push(node->element);

        inorder(node->right, expression);

        if (node->right) expression.push(')');
    }
    bool dfs(std::unique_ptr<Node> const& node) {
        if (node) {
            if (node->element == '0') return false;
            if (node->element == '1') return true;

            if (node->element == '&')
                return (dfs(node->left) && dfs(node->right));

            if (node->element == '|')
                return (dfs(node->left) || dfs(node->right));
        }
    }

   private:
    std::unique_ptr<Node> root_;
    bool result_;
};

int main(int argc, char const* argv[]) {
    /*ex1: (F&&T)||T */
    std::vector<char> descriptopn1{'0', '1', '&', '1', '|'};
    /*ex2: (T||F)&&(F&&F)*/
    std::vector<char> descriptopn2{'1', '0', '|', '0', '0', '&', '&'};
    /*ex3: F*/
    std::vector<char> descriptopn3{'0'};
    /*ex4: T&&(T||F)*/
    std::vector<char> descriptopn4{'1', '1', '0', '|', '&'};

    BinaryExpressTree expression_tree1(descriptopn1);
    expression_tree1.showExpression();
    expression_tree1.test();

    BinaryExpressTree expression_tree2(descriptopn2);
    expression_tree2.showExpression();
    expression_tree2.test();

    BinaryExpressTree expression_tree3(descriptopn3);
    expression_tree3.showExpression();
    expression_tree3.test();

    BinaryExpressTree expression_tree4(descriptopn4);
    expression_tree4.showExpression();
    expression_tree4.test();
    return 0;
}
