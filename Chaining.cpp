#include "Chaining.h"
#include <vector>
using namespace std;
// void Chaining::increasesize(){
//     syze=syze+1;
// }
// void Chaining::decreasesize(){
//     syze=syze-1;
// }
// int Chaining::getsize(){
//     return syze;
// }
void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    syze++;
    Account Accounti;
    Accounti.id=id;
    Accounti.balance=count;       
    int hashvalue=hash(id);
    bankStorage2d[hashvalue].push_back(Accounti);
    // bankStorage2d[hashvalue]
    
}
int part(vector<int> &a,int low,int high){
	int pivot=high;
	int j=low-1;
	for(int i=low;i<=high-1;i++){
		if(a[i]<a[pivot]){
			j++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	int temp=a[j+1];
	a[j+1]=a[pivot];
	a[pivot]=temp;
	return j+1;


}
void quicksort(vector<int> &a,int low,int high){
	if(low<high){
		int p=part(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}
std::vector<int> Chaining::getTopK(int k) {
    std::vector<int> green;
            for (int i = 0; i < 10069; i++)
            {
                for(int j=0;j<bankStorage2d[i].size();j++){
                    if (bankStorage2d[i][j].id != "")
                {
                    green.push_back(bankStorage2d[i][j].balance);
                }
                }
                
            }
            
            int len = green.size();
            
          
            quicksort(green,0,len-1);
            // sort(green.begin(),green.end());
            green.erase(green.begin(), green.begin() + len - k);
            // reverse(green.begin(), green.end());

            std::vector<int> green2;
            for(int p=0;p<green.size();p++){
                green2.push_back(green[green.size()-1-p]);
            }
            return green2;
}

int Chaining::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int hashvalue=hash(id);
    for(int j=0;j<bankStorage2d[hashvalue].size();j++){
        if(bankStorage2d[hashvalue][j].id==id){
            return bankStorage2d[hashvalue][j].balance;
        }
    }
    if(bankStorage2d[hashvalue][bankStorage2d[hashvalue].size()-1].id!=id){
        return -1;
    }
    
    
     // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int hashvalue=hash(id);
    int poppy=1;
    for(int j=0;j<bankStorage2d[hashvalue].size();j++){
        if(bankStorage2d[hashvalue][j].id==id){
            bankStorage2d[hashvalue][j].balance+=count;
            poppy=0;

        }
    }
    if(poppy==1){
        createAccount(id,count);
    }
}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int hashvalue=hash(id);
    bool pop=false;
    // int max=bankStorage2d[0][0].balance;
    for(int j=0;j<bankStorage2d[hashvalue].size();j++){
                if(bankStorage2d[hashvalue][j].id==id){
                    pop=true;
                }
                

            }        
    

        

    return pop; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    
    int hashvalue=hash(id);
    bool pop=false;
    // int max=bankStorage2d[0][0].balance;
    for(int j=0;j<bankStorage2d[hashvalue].size();j++){
                if(bankStorage2d[hashvalue][j].id==id){
                    pop=true;
                    bankStorage2d[hashvalue][j].id="";
                    bankStorage2d[hashvalue][j].balance=0;
                    syze=syze-1;
                }
                

            }        
    return pop; // Placeholder return value
}
int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
    
    return syze;
}

int Chaining::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int len;
    
    long long int hashval=0;
    len = id.length();
    int i=1;
    while(i<len){
        //hashval=hashval + powpow((int(id[i])-int(id[i-1])),2)*(powpow(37,i));
        hashval=int(id[i])*int(id[i])*int(id[i]);
        i++;
    }
    hashval=hashval%10069;
    return hashval;
    // Placeholder return value
}
