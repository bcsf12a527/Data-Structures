# include "AVLTree.cpp"

int main ()
{
	AVLTree<int> tree ;

	for (size_t i = 0; i < 50; i++)
	{
		tree.SetNodeR(i);
	}

	cout << "In order printing is : " << endl ;
	tree.In_Order_Print() ;
	cout << endl;

	AVLTree<int> tree2 = tree;
	
	cout << "Pre order printing is : " << endl;
	tree2.Pre_Order_Print();
	cout << endl;

	return 0 ;
}
