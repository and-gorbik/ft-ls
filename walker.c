#include "walker.h"

void push(t_stack *stack, struct stat *stat)
{

}

struct stat pop(t_stack *stack)
{

}

void walk(const char *root)
{
	t_stack	stack;
	char	*path; 

	path = root;
	while (path || stack.top)
	{
		if (stack.top) {

		}
	}
}

/*

void preOrder(Node * top) {
	Stack<Node *> stack = new Stack<> ();
	while (top != nullptr || !stack.empty()) {
		if (!stack.empty())
			top = stack.pop();
		
		while (top != nullptr) {
			visit(top);
			if (top->right != nullptr)
				stack.push(top->right);
			top = top->left;
		}
	}
}


*/