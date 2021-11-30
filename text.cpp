//Ho ten: NGUYEN THI VAN KHANH
//MSSV:6151071008
//Ngay sinh:02/09/2002
//Email:lethiha08041980@gmail.com
#include <iostream>
#include <conio.h>
using namespace std;

typedef int Item;

struct Node {
    Item data;
    Node *next;
};

struct Slist {
    Node *head;
    Node *tail;
    long size;
    Slist();
    bool isEmpty();
    Node* createNode(Item v);
    void addFirst(Item v);
    Node* insertAfter(Node* p, Item v);
    Node* insertBefore(Node* p, Item v);
    void addLast(Item v);
    Node* Previous(Node* p);
    void removeFirst();
    void removeLast();
    void remove(Node* p);
};

Slist::Slist() {
    head = NULL;
    tail = NULL;
    size = 0;
}

bool Slist::isEmpty() {
    if(head == NULL && tail == NULL)
        return true;
    else return false;
}

Node* Slist::createNode(Item v) {
    Node* p = new Node;
    p->data = v;
    p->next = NULL;
    return p;
}

void Slist::addFirst(Item v) {
    Node* p = createNode(v);
    p->next = head;
    head = p;
    if(size == 0)
        tail = p;
    size++;
}

void Slist::addLast(Item v) {
    Node* p = createNode(v);
    if (size == 0){
		head = p;
		tail = p;
	}
	else{
		tail->next = p;
		tail = p;	  
	}
	size++;	  
}

Node* Slist::insertAfter(Node* p, Item v) {
    if (p == tail)
		addLast(v);
	else {
		Node *q = createNode(v);
		q->next = p->next;
		p->next = q;	  
	}
	size++;
}

Node* Slist::Previous(Node* p){
    Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}

Node* Slist::insertBefore(Node*p, Item v) {
    if (p == head)
		addFirst(v);
	else{		
		Node *pre = Previous(p);
		insertAfter(pre, v);
	}
}

void Slist::removeFirst(){
    if(size == 0)
        return;
    Node* t = head;
    head = head->next;
    delete t;
    size--;
}

void Slist::removeLast(){
    if(size == 0)
        return;
    else if(size == 1){
        delete head;
        size--;
    }
    else{
        Node* pre = Previous(tail);
        Node* t = tail;
        pre->next = NULL;
        tail = pre;
        delete t;
        size--;
    }
}

void Slist::remove(Node* p){
    if(p == head)
        removeFirst();
    else if(p == tail)
        removeLast();
    else{
        Node* pre = Previous(p);
        pre->next = p->next;
        delete p;
        size--;
    }
}

//1.	Nhập vào danh sách số nguyên với số lượng phần tử biết trước. Số lượng phần tử do người dùng nhập vào.
void inputSize(Slist &sl) {
    int x, n;
    cout << "Enter size of list: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        cout << "Enter the " << i+1 << " element: ";
        cin >> x;
        sl.addLast(x);
    }
}

//2.	Nhập vào danh sách số nguyên. Ngừng nhập khi người dùng nhập vào số 0. 
void inputNotSize(Slist &sl) {
    int x, i = 0;
    while(x != 0) {
        cout << "Enter the " << i+1 << " element: ";
        cin >> x;
        if(x != 0) {
            sl.addLast(x);
            i++;
        }
    }
}

//3.	In ra màn hình danh sách vừa nhập. 
void Traverser(Slist sl) {
    Node *p  = sl.head;
    while(p != NULL) {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl; 
}

//4.	Tính trung bình cộng các phần tử có trong danh sách.
float Average(Slist sl) {
    int Sum = 0, count = 0;
    float Ave = 0;
    Node* p = sl.head;
    while(p != NULL) {
        Sum += p->data;
        count++;
        p = p->next;
    }
    Ave = (float)Sum / count;
    return Ave;
}

//5.	Đếm số phần tử trong danh sách.
int NumberofList(Slist sl) {
    int count = 0;
    Node* p = sl.head;
    while(p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

//6.	Chèn phần tử có giá trị y vào sau các phần tử có giá trị x.
void insertAfterX(Slist &sl) {
    int x, y, count = 0;
    cout << "Enter value need to insert (y): ";
    cin >> y;
    cout << "Enter value in list (x): ";
    cin >> x;
    Node* p = sl.head;
    while(p != NULL) {
        if(x == p->data) {
            sl.insertAfter(p, y);
            count++;
        }    
        p = p->next;
    }
    if(count == 0)
        cout << "\nThis value is not in the list!";
    else {
        cout << "\nList after 'insert after': ";
        Traverser(sl);
    }
}

//7.	Chèn phần tử có giá trị y vào trước các phần tử có giá trị x.
void insertBeforeX(Slist &sl) {
    int x, y, count = 0;
    cout << "Enter value need to insert (y): ";
    cin >> y;
    cout << "Enter value in list (x): ";
    cin >> x;
    Node* p = sl.head;
    while(p != NULL) {
        if(x == p->data) {
            sl.insertBefore(p, y);
            count++;
        }
        p = p->next;    
    }
    if(count == 0)
        cout << "\nThis value is not in the list!";
    else {
        cout << "\nList after 'insert before': ";
        Traverser(sl);
    }
}

//8.	Cho biết giá trị của nút thứ k trong danh sách (k bắt đầu từ 0).
void getValueAtk(Slist sl) {
    int k, index = 0, x = 0;
    cout << "Enter position want to search: ";
    cin >> k;
    Node* p = sl.head;
    while(p != NULL) {
        ++index;
        if( k == index)
            x = p->data;
        p = p->next;
    }
    cout << "The value at k is: " << x << endl;
}

//9.	Tìm phần tử lớn nhất (nhỏ nhất) trong danh sách.
void findMaxMin(Slist sl) {
    int key;
    Node* p = sl.head;
    cout << "1. Find max.\n";
    cout << "2. Find min.\n";
    cout << "Select function: "; cin >> key;
    if(key == 1) {
            int Max = sl.head->data;
            while(p != NULL) {
                if(p->data > Max)
                    Max = p->data;
                p = p->next;
            }
            cout << "The max value in list is: " << Max << endl;
    }
    else if(key == 2) {
        int Min = sl.head->data;
        while(p != NULL) {
            if(p->data < Min)
                Min = p->data;
            p = p->next;
        }
        cout << "The min value in list is: " << Min << endl;
    }
}

//10.	Xóa một phần tử có khóa là x.
void DeleteNode(Slist &sl) {
    int x;
    cout << sl.size << endl;
    cout << "Enter key want to delete: ";
    cin >> x;
    Node* p = sl.head;
    while(p != NULL) {
        if(x == p->data)
            sl.remove(p);
        p = p->next;
    }
    cout << "List after delete: ";
    Traverser(sl);
}

//11.	Xóa tất cả các phần tử có khóa là x.

//12.	Kiểm tra xem dãy có phải là dãy tăng.
void isIncrease(Slist sl) {
    int count;
    Node *p, *q;
    p = sl.head;
    while(p != NULL) {
        q = p->next;
        if(p->data < q->data) {
            count++;
        }
        p = p->next;
    }
    if(count == sl.size - 1)
        cout << "This is increase list!";
    else
        cout << "This is not increase list!";
}

//13.	Sắp xếp danh sách vừa nhập theo chiều tăng dần. 
void Sort(Slist sl) {
    Node *p, *q;
    p = sl.head;
    while(p != NULL) {
        q = p->next;
        while( q != NULL) {
            if(p->data > q->data) {
                Item t;
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
            q = q->next;
        }
        p = p->next;
    }
    cout << "List after sort: ";
    Traverser(sl);
}

int main() {
    Slist sl;
    cout << "**List have size: " << endl;
    inputSize(sl);
    cout << "\n________________________________________\n" << endl;
    cout << "**List not size: " << endl;
    inputNotSize(sl);
    cout << "\n________________________________________\n" << endl;
    cout << "List is: ";
    Traverser(sl);
    cout << "\n________________________________________-\n" << endl;
    cout << "Average value of list is: " << Average(sl) << endl;
    cout << "\n________________________________________\n" << endl;
    cout << "Number of list is: " << NumberofList(sl) << endl;
    cout << "\n________________________________________\n" << endl;
    insertAfterX(sl);
    cout << "\n________________________________________\n" << endl;
    insertBeforeX(sl);
    cout << "\n________________________________________\n" << endl;
    getValueAtk(sl);
    cout << "\n________________________________________\n" << endl;
    findMaxMin(sl);
    cout << "\n________________________________________\n" << endl;
    Sort(sl);
}