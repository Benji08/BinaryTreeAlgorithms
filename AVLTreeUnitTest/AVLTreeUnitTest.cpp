#include "../AVLTreeLib/AVLTree.h"
#include <gtest/gtest.h>

namespace AVLTreeUnitTest
{

		TEST(AVLTreeUnitTest, ConstructEmpty)
		{
			AVLTree<int, int> tree;
			tree.add(10, 10);
			tree.add(20, 20);
			std::string expected = "([10,10],,([20,20],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, leftRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(60, 60);
			tree.add(20, 20);
			tree.add(70, 70);
			tree.add(10, 10);
			tree.add(30, 30);
			tree.add(80, 80);
			tree.add(25, 25);
			tree.add(40, 40);
			std::string expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
            ASSERT_EQ(expected, tree.toString());
			tree.add(50, 50);
			expected = "([60,60],([30,30],([20,20],([10,10],,),([25,25],,)),([40,40],,([50,50],,))),([70,70],,([80,80],,)))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, rightLeftRootRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(10, 10);
			tree.add(30, 30);
			std::string expected = "([10,10],,([30,30],,))";
            ASSERT_EQ(expected, tree.toString());
			tree.add(20, 20);
			expected = "([20,20],([10,10],,),([30,30],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, rightLeftRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(60, 60);
			tree.add(20, 20);
			tree.add(70, 70);
			tree.add(10, 10);
			tree.add(30, 30);
			tree.add(80, 80);
			tree.add(25, 25);
			tree.add(40, 40);
			std::string expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
            ASSERT_EQ(expected, tree.toString());
			tree.add(22, 22);
			expected = "([60,60],([25,25],([20,20],([10,10],,),([22,22],,)),([30,30],,([40,40],,))),([70,70],,([80,80],,)))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, rightRootRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(30, 30);
			tree.add(20, 20);
			std::string expected = "([30,30],([20,20],,),)";
            ASSERT_EQ(expected, tree.toString());
			tree.add(10, 10);
			expected = "([20,20],([10,10],,),([30,30],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, rightRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(30, 30);
			tree.add(20, 20);
			tree.add(80, 80);
			tree.add(10, 10);
			tree.add(60, 60);
			tree.add(90, 90);
			tree.add(50, 50);
			tree.add(70, 70);
			std::string expected = "([30,30],([20,20],([10,10],,),),([80,80],([60,60],([50,50],,),([70,70],,)),([90,90],,)))";
            ASSERT_EQ(expected, tree.toString());
			tree.add(40, 40);
			expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, leftRightRootRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(30, 30);
			tree.add(10, 10);
			std::string expected = "([30,30],([10,10],,),)";
            ASSERT_EQ(expected, tree.toString());
			tree.add(20, 20);
			expected = "([20,20],([10,10],,),([30,30],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, leftRightRotationAfterInsert)
		{
			AVLTree<int, int> tree;
			tree.add(30, 30);
			tree.add(20, 20);
			tree.add(80, 80);
			tree.add(10, 10);
			tree.add(50, 50);
			tree.add(90, 90);
			tree.add(40, 40);
			tree.add(60, 60);
			std::string expected = "([30,30],([20,20],([10,10],,),),([80,80],([50,50],([40,40],,),([60,60],,)),([90,90],,)))";
            ASSERT_EQ(expected, tree.toString());
			tree.add(70, 70);
			expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, ConstructEmptyy)
		{
			AVLTree<int, int> tree;
			std::string expected = "";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertToEmpty)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			std::string expected = "([10,100],,)";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
			std::string expected = "([10,100],([5,50],,),)";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(20, 200);
			std::string expected = "([10,100],,([20,200],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(20, 200);
			tree.add(5, 50);
			std::string expected = "([10,100],([5,50],,),([20,200],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
			tree.add(20, 200);
			std::string expected = "([10,100],([5,50],,),([20,200],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelLeftLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(10, 100);
			std::string expected = "([50,500],([20,200],([10,100],,),),([80,800],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelLeftLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(30, 300);
			tree.add(10, 100);
			std::string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelLeftRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(30, 300);
			std::string expected = "([50,500],([20,200],,([30,300],,)),([80,800],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelLeftRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(10, 100);
			tree.add(30, 300);
			std::string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelRightLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(70, 700);
			std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelRightLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(90, 900);
			tree.add(70, 700);
			std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelRightRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(90, 900);
			std::string expected = "([50,500],([20,200],,),([80,800],,([90,900],,)))";
            ASSERT_EQ(expected, tree.toString());
		}
		TEST(AVLTreeUnitTest, insertOnThe3LevelRightRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(70, 700);
			tree.add(90, 900);
			std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
            ASSERT_EQ(expected, tree.toString());
		}
          TEST(AVLTreeUnitTest, findInEmpty)
		{
			AVLTree<int, int> tree;
            ASSERT_EQ(0, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findNotExisted)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
			tree.add(20, 200);
            ASSERT_EQ(NULL,tree.search(2));
            ASSERT_EQ(NULL,tree.search(7));
            ASSERT_EQ(NULL,tree.search(12));
            ASSERT_EQ(NULL,tree.search(24));
		}
		TEST(AVLTreeUnitTest, findOnThe1LevelNoChildren)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
            ASSERT_EQ(100, tree.search(10));
			tree.add(5, 50);
            ASSERT_EQ(100, tree.search(10));
			tree.add(20, 200);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe1LevelIsLeftChild)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe1LevelIsRightChild)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(20, 200);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe1LevelAreChildren)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
			tree.add(20, 200);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe2LevelOnTheLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
            ASSERT_EQ(50, tree.search(5));
		}
		TEST(AVLTreeUnitTest, findOnThe2LevelOnTheRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(20, 200);
            ASSERT_EQ(200, tree.search(20));
		}
		TEST(AVLTreeUnitTest, findOnThe2LevelOnTheLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(20, 200);
			tree.add(5, 50);
            ASSERT_EQ(50, tree.search(5));
		}
		TEST(AVLTreeUnitTest, findOnThe2LevelOnTheRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(10, 100);
			tree.add(5, 50);
			tree.add(20, 200);
            ASSERT_EQ(200, tree.search(20));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelLeftLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(10, 100);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelLeftLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(30, 300);
			tree.add(10, 100);
            ASSERT_EQ(100, tree.search(10));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelLeftRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(30, 300);
            ASSERT_EQ(300, tree.search(30));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelLeftRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(10, 100);
			tree.add(30, 300);
            ASSERT_EQ(300, tree.search(30));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelRightLeftThereIsNoRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(70, 700);
            ASSERT_EQ(700, tree.search(70));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelRightLeftThereIsRight)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(90, 900);
			tree.add(70, 700);
            ASSERT_EQ(700, tree.search(70));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelRightRightThereIsNoLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(90, 900);
            ASSERT_EQ(900, tree.search(90));
		}
		TEST(AVLTreeUnitTest, findOnThe3LevelRightRightThereIsLeft)
		{
			AVLTree<int, int> tree;
			tree.add(50, 500);
			tree.add(20, 200);
			tree.add(80, 800);
			tree.add(70, 700);
			tree.add(90, 900);
            ASSERT_EQ(900, tree.search(90));
		}
};

