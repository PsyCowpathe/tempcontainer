/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:07:24 by agirona           #+#    #+#             */
/*   Updated: 2022/12/14 20:57:05 by agirona          ###   ########lyon.fr   */
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

	tree.insert(15);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(18);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(16);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(5);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(28);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(31);
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(9);
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
	std::cout << "==================END================" << std::endl;





	return (0);
}
