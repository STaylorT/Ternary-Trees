// Author: Taylor Thomas
// 3/2021
// Ternary Trees

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string>
using namespace std;
const int nuller = -2147482648;

struct node
 {
        int data1 ;
        int data2 ;
        node *left = NULL;
        node *mid  = NULL;
        node *right = NULL;
        int depth = 0;
};

node* newNode(int data)
{
	node *temp = new node();
	temp->data1 = data;
	temp->data2 = nuller;
	temp->left = NULL;
	temp->mid = NULL;
	temp->right = NULL;
	return temp;
}

void setValuefor2(node* node, int num){
	if (node->data1 > num){
		node->data2 = node->data1;
		node->data1 = num;
		}
		
	else 
	node->data2 = num;
	}


void insert(node* root, int newData){
	//fill second data in first node first
	if (root->data2 == nuller)
		setValuefor2(root, newData);
	//compare data and data2, then check if new node is needed;	
	else if(newData <= root->data1){
		if (root->left ==NULL){
			root->left = newNode(newData);
			}
		else 
		insert(root->left, newData);
			}
	//create right child or insert into right child
	else if(newData > root->data2){
		if (root->right ==NULL)
			root->right = newNode(newData);
		else insert(root->right, newData);
	}
	//create middle child or insert into middle child
	else if (newData > root->data1 && newData <= root->data2){
		if (root->mid == NULL)
			root->mid = newNode(newData);
		else 
		insert(root->mid, newData);
		}
	
	}
	
void printTern(node *ternTree){

	if (ternTree->left != NULL){//make way to bottom left element & print
		cout << "(" ;
		printTern(ternTree->left);
		cout << ") " ;
	}
	// print smaller value of node
	cout << ternTree->data1 << " ";
	
	if (ternTree->mid !=NULL){ //print middle nodes
		cout << "(";
		printTern(ternTree->mid);
		cout << ")";
	}
	// print greater value of node
	if (ternTree->data2 !=nuller){
		cout << " " << ternTree->data2;
		}
	// print right children
	if (ternTree->right !=NULL){
	cout << " (";
	printTern(ternTree->right);
	cout << ")";
	}
	
}

int main(int argc, char* argv[]){
	int n = stoi(argv[1]);
	int input;
	cin >> input;
	// initializing first value
	node *ternaryTree = newNode(input);
	for (int i = 1; i < n ; i++){ //loop to take all inputs given
		cin >> input;
		insert(ternaryTree,input);//insert on each iteration
		} 
	printTern(ternaryTree);
	


return 0;
}


