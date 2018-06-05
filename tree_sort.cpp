//Tree Sort algorithm test, phase 1

#include <iostream>
#include <string>

class Tree{
	public:
		static Tree * start;
		Tree * parent;
		Tree * left;
		Tree * right;
		int value;

		Tree(Tree * _parent, int _value);

		void push(int _value);
};

Tree * Tree::start = nullptr;

Tree::Tree(Tree * _parent, int _value){
	parent = _parent;
	left = nullptr;
	right = nullptr;
	value = _value;
}

void Tree::push(int _value){
	if(_value < value){
		if(!left)left = new Tree(this, _value);
		else left->push(_value);
	}
	else{
		if(!right)right = new Tree(this, _value);
		else right->push(_value);
	}
}

void Sort(Tree * x){
	if(x->left)Sort(x->left);
	if(x->right){
		std::cout << x->value << std::endl;
		if(x->parent){
			x->parent->left = x->right;
			x->right->parent = x->parent;
		}
		else{
			Tree::start = x->right;
			x->right->parent = nullptr;
		}
		Tree * xc = x->right;
		delete x;
		Sort(xc);
	}
	else{
		std::cout << x->value << std::endl;
		if(x->parent)x->parent->left = nullptr;
		delete x;
	}
}

int main(int argc, char **argv){

	std::string in;

	while(std::getline(std::cin, in)){
		if(in.empty())break;
		if(!Tree::start)Tree::start = new Tree(nullptr, std::stoi(in));
		else Tree::start->push(std::stoi(in));
	}

	Sort(Tree::start);

	return 0;
}