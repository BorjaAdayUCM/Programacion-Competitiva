#include<iostream>
#include<vector>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

const int MAXN = 26;
class Trie {
    int prefixes, words;
    vector<Trie*> child; 
    public:
        Trie():prefixes(0),words(0),child(MAXN, nullptr) {}
        
        ~Trie() {
            for(int i = 0; i < MAXN; ++i) 
                delete child[i];
        }

        void add(const char*s) {
            if(*s =='\0') ++words;
            else{
                Trie*t;
                if(child[*s -'a'] == nullptr) {
                    t = child[*s -'a'] = new Trie();
                    t->prefixes = 1;
                }
                else{
                    t = child[*s -'a'];
                    t->prefixes++;
                }
                t->add(s+1);
            }
        }

        int getPulsations(const char* s, int  k){
            if(*s =='\0')
                return k;
            else{
                Trie *t = child[*s - 'a'];
                if(t == NULL) return 0;
                if(prefixes != t->prefixes) k++; 
                return t->getPulsations(s+1, k);
            }
            return 0;
        }
};




int main() {
    int N ;
    while(cin >> N){
        Trie trie = Trie();
        string pa;
        vector<string> diccionario;
        while(N--){
            cin >> pa;
            trie.add(pa.c_str());
            diccionario.push_back(pa);
        }
        double suma = 0;
        for(int i = 0; i < diccionario.size(); i++){
            suma += trie.getPulsations(diccionario[i].c_str(),0); 
        }
        cout << fixed << setprecision(2) << round((suma/diccionario.size()) * 100) / 100 << '\n';
    }

}