/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:07:24 by agirona           #+#    #+#             */
/*   Updated: 2022/12/12 19:42:13 by agirona          ###   ########lyon.fr   */
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
			std::cout<<"R----";
			indent += "     ";
		}
		else {
			std::cout<<"L----";
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

	tree.insert(18);
	tree.insert(5);
	tree.insert(1);
	tree.insert(171);
	tree.insert(21);
	tree.insert(-42);
	tree.insert(2);
	tree.erase(1);
	printHelper(tree.get_origin(), "", true, true);
	return (0);
}
