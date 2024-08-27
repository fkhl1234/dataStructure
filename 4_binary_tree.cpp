#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class binary {
    T data;
    binary* left;
    binary* right;
    
    public:
        binary(T data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        } 

        void insert(T data) {
            if(this->data < data) {
                if(this->right == NULL) {
                    this->right = new binary(data); // 동적할당을 하지 않을 시 scope가 끝나면 인스턴스 자체가 사라짐
                    return;
                }
                else {
                    (this->right)->insert(data);
                }
            }
            else {
                if(this->left == NULL) {
                    this->left = new binary(data);
                    return;
                }
                else {
                    (this->left)->insert(data);
                }
            }
            return;
        }

        bool search(T data) {
            if(this->data==data) {
                return true;
            }
            else if(this->data<data) {
                if(this->right!=NULL)
                    (this->right)->search(data);
                else
                    return false;
            }
            else {
                if(this->left!=NULL)
                    (this->left)->search(data);
                else
                    return false;
            }
        }

        void BFS() {
            stack<binary<T>*> bfs;
            
            bfs.push(this);

            while(!bfs.empty()) {
                auto temp = bfs.top();
                bfs.pop();

                printf("%d ", temp->data);

                if(temp->left!=NULL) {
                    bfs.push(temp->left);
                }
                if(temp->right!=NULL) {
                    bfs.push(temp->right);
                }
            }
        }
        
        bool remove(T data) {
            binary* ptr = _search(data);

            if(ptr==nullptr) {
                printf("This element doesn't exist\n");
                return false;
            }

            if(ptr->right!=nullptr) {
                binary* temp = ptr->right;

                binary* previous = ptr->right;
                while(temp->left!=nullptr) {
                    previous = temp;
                    temp = previous->left;
                }

                if(temp->right!=nullptr) {
                    
                    // 대체할 포인터의 right노드 처리
                }


            }

            return true;
        }

    private:
        binary* _search(T data) {
            if(data==this->data) {
                return this;
            } 
            else if(data>this->data) {
                if(this->right!=nullptr) {
                    (this->right)->_search();
                }
                else return nullptr;
            }
            else {
                (this->left!=nullptr) {
                    (this->left)->_search();
                }
                else return nullptr;
            }
        }
};



int main() {
    auto test = binary<int>(1);

    test.insert(4);
    test.insert(3);
    test.insert(2);

    test.BFS();

    bool check = test.search(3);

    printf("%d\n", check ? 1 : 0);

    return 0;
}