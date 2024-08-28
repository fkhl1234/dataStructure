#include <iostream>
#include <stack>
#include <utility>

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
            pair<binary*, binary*> target = _search(data); 

            binary* cur = target.first(); // 찾는 노드
            binary* parent = target.second(); // 찾는 노드의 부모 노드

            if(cur==nullptr) {
                printf("This element doesn't exist\n");
                return false;
            }

            if(cur->right!=nullptr) {
                binary* temp = cur->right; // 바꿀 노드
                
                binary* previous = cur->right;
                while(temp->left!=nullptr) {
                    previous = temp;
                    temp = previous->left;
                }

                if(temp->right!=nullptr) {
                    previous->left = temp->right; // 교체 노드 자리 채우기

                    parent->

                    temp->right = cur->right;
                    temp-left = cur->left; // 원래 노드의 링크 교체

                    delete cur; // 노드 삭제
                    // 대체할 포인터의 right노드 처리
                } // 오른쪽 트리가 있을 경우
                else if(temp->left!=nullptr) {
                    
                } // 왼쪽 트리만 있을 경우


            }

            return true;
        }
        /*
            노드 삭제 의사 코드
            1. 삭제할 노드의 오른쪽 트리가 존재할 경우
                a. 삭제할 노드 current와 그 부모 노드 cur_parent
                b. 자리를 채울 대체 노드 temp와 그 부모 노트 temp_parent: 오른쪽 트리의 가장 왼쪽에 있는(작은) 노드
                
                temp  노드의 빈자리 채우기
                c. temp의 right에 연결되어 있는 노드를 temp_parent의 left에 연결

                current 노드 대체 작업
                d. cur_parent의 right 링크에 temp를 연결
                e. temp의 right와 left 링크에 current의 right와 left에 연결되어 있는 노드를 연결
        */

    private:
        pair<binary*, binary*> _search(T data) {
            binary* cur = this;
            binary* parent = this;
            while(1) {
                if(data==cur->data) {
                    return make_pair(cur, parent);
                } 
                else if(data>cur->data) {
                    if(cur->right!=nullptr) {
                        parent = cur;
                        cur = parent->right;
                    }
                    else return make_pair(nullptr, nullptr);
                }
                else {
                    if(cur->left!=nullptr) {
                        parent = cur;
                        cur = parent->left;
                    }
                    else return make_pair(nullptr, nullptr);
                }   
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