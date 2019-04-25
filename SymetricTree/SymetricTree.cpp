#include <vector>
#include <stack>
#include <iostream>

struct Node
{

	int data;
	std::vector<Node*> children;

	Node(int data,size_t branchFactor)
	{
		this->data = data;

		for (size_t i = 0; i < branchFactor; ++i)
		{
			children.push_back(nullptr);
		}
	}

	~Node()
	{
		for (size_t i = 0; i < children.size(); ++i)
		{
			delete children[i];
		}
	}

	bool operator==(const Node& other)
	{
		if (true)
		{

		}
		return data == other.data;
	}
};




bool isSymetric(const std::vector<Node*>& prevLevel, size_t branchFactor)
{
	
	bool isLast = true;

	for (size_t i = 0; i < prevLevel.size(); ++i)
	{
		if (prevLevel[i])
		{
			isLast = false;
		}
	}

	if (isLast)
	{
		return true;
	}

	bool _isSymetric = true;

	size_t size = prevLevel.size();

	for (size_t i = 0; i < size/2; ++i)
	{
		bool rightNull = (!prevLevel[i]) ? true : false;
		bool leftNull = (!prevLevel[size - 1 - i]) ? true : false;

		if (!rightNull && leftNull || rightNull && !leftNull)
		{
			_isSymetric = false;
		}
		if (!rightNull && !leftNull && !(*prevLevel[i] == *prevLevel[size-1-i]))
		{
			_isSymetric = false;
		}
	}

	if (_isSymetric)
	{
		std::vector<Node*> nextLevel;

		nextLevel.reserve(prevLevel.size() * branchFactor);

		for (size_t i = 0; i < size; ++i)
		{
			if (prevLevel[i])
			{
				nextLevel.insert(nextLevel.begin(), prevLevel[i]->children.begin(), prevLevel[i]->children.end());
			}
		}

		return isSymetric(nextLevel, branchFactor);
	}

	return false;
}

bool isSymetricMain(const Node* root, size_t branchFactor)
{
	std::vector<Node*> initLevel;

	for (size_t i = 0; i < branchFactor; i++)
	{
		initLevel.push_back(root->children[i]);
	}

	return isSymetric(initLevel, branchFactor);
}

int main()
{
	Node* root;
	size_t branchFactor = 4;

	root = new Node(4, branchFactor);

	root->children[0] = new Node(3, branchFactor);
	root->children[1] = new Node(5, branchFactor);
	root->children[2] = new Node(5, branchFactor);
	root->children[3] = new Node(3 , branchFactor);

	root->children[0]->children[0] = new Node(9, branchFactor);
	root->children[0]->children[1] = new Node(6, branchFactor);
	root->children[3]->children[3] = new Node(9, branchFactor);
	root->children[3]->children[2] = new Node(6, branchFactor);

	root->children[0]->children[0]->children[0] = new Node(1, branchFactor);

	std::cout << isSymetricMain(root, branchFactor);
}