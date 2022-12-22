/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:07:24 by agirona           #+#    #+#             */
/*   Updated: 2022/12/22 12:07:48 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "tree.tpp"

void printHelper(ft::tree<ft::pair<int, int> >::node *root, std::string indent, bool last, bool first) 
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
	ft::tree<ft::pair<int, int> >			tree;

	tree.insert(ft::make_pair<int, int>(40, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(30, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(60, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(20, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(50, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(80, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(45, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(55, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	/*tree.insert(ft::make_pair<int, int>(55, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(65, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(90, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(62, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;

	tree.insert(ft::make_pair<int, int>(-445445, 1));
	printHelper(tree.get_origin(), "", true, true);
	std::cout << "==================END================" << std::endl;


	tree.erase(ft::make_pair<int, int>(90, 1));
	printHelper(tree.get_origin(), "", true, true);*/

	ft::elem<ft::pair<int, int> > *it = tree.get_origin();
	ft::elem<ft::pair<int, int> > *prev;
	int		count = 0;


	while (it != NULL)
	{
		prev = it;
		std::cout << it->get_key() << std::endl;
		it = it->next();
	}

	std::cout << std::endl;
	it = prev;

	while (it != NULL)
	{
		prev = it;
		std::cout << it->get_key() << std::endl;
		it = it->prev();
		count++;
	}

	std::cout << std::endl;
	it = prev;

	while (it != NULL)
	{
		std::cout << it->get_key() << std::endl;
		it = it->next();
		count++;
	}







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
