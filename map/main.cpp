/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:07:24 by agirona           #+#    #+#             */
/*   Updated: 2022/12/15 14:45:20 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "avl.tpp"

void printHelper(ft::tree<int>::node *root, std::string indent, bool last, bool first) 
{
	if (root != nullptr) 
	{
		std::cout<<indent;
		if (first) {
			std::cout<<"Root-";
			indent += "     ";
		}
		else if (last) {
			std::cout<<"D----";
			indent += "     ";
		}
		else {
			std::cout<<"G----";
			indent += "|    ";
		}

		std::cout << "(" << root->get_key() << ")" << std::endl;
		printHelper(root->get_left(), indent, false, false);
		//exit(0);
		printHelper(root->get_right(), indent, true, false);
		if (first)
			std::cout << std::endl;
	}
	else if (first)
		std::cout << "NULL" << std::endl << std::endl;

}

int		main(void)
{
	ft::tree<int>			tree;

	tree.insert(50);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(25);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(75);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(15);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(40);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(60);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(80);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(35);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(55);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(65);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(90);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(62);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.erase(-445445);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;







	/*tree.insert(9);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(-52);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(48);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(58);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(59);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(60);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(50);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;



	tree.insert(27);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(26);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(1);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(51);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;*/





	return (0);
}
