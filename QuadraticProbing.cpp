#include "QuadraticProbing.h"
#include <vector>
using namespace std;
// int QuadraticProbing::powpow(int a, int p){
//         int ans=1;
//         for(int i=0;i<p;i++){
//             ans=ans*a;
//         }
//         return ans;
//       }
// void QuadraticProbing::increasesize(){
//     syze=syze+1;
// }
// void QuadraticProbing::decreasesize(){
//     syze=syze-1;
// }
// int QuadraticProbing::getsize(){
//     return syze;
// }
void QuadraticProbing::createAccount(std::string id, int count) {
    syze++;
     
     int kk=0;
    Account Accounti;
    Accounti.id=id;
    Accounti.balance=count;       
    int hashvalue=hash(id);
    if(bankStorage1d[hashvalue].id==""){
        bankStorage1d[hashvalue]=Accounti;
    }
    else {
        while(bankStorage1d[hashvalue].id!=""){
            
                kk=kk+1;
                hashvalue=(hashvalue+(kk*kk))%100000;
                
                if(bankStorage1d[hashvalue].id==""){
                    bankStorage1d[hashvalue]=Accounti;
                    break;
                }
                
            }
            // else if(hashvalue==99999){
            //     hashvalue=(hashvalue+(kk**2))%100000;
            //     if(bankStorage1d[hashvalue].id==""){
            //         bankStorage1d[hashvalue]=Accounti;
            //     }
            // }
        }
    }
    // IMPLEMENT YOUR CODE HERE

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
std::vector<int> QuadraticProbing::getTopK(int k) {
    std::vector<int> green;
            for (int i = 0; i < 100000; i++)
            {
                if (bankStorage1d[i].id != "")
                {
                    green.push_back(bankStorage1d[i].balance);
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

int QuadraticProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    // hashvalue=hash(id);
    // if(bankStorage1d[hashvalue].id==id){
    //     return bankStorage1d[hashvalue].balance;
    // }
    // else {
    //     while(bankStorage1d[hashvalue].id!=id){
            
    //             kk=kk+1;
    //             hashvalue=(hashvalue+(kk**2))%100000;
                
    //             if(bankStorage1d[hashvalue].id==id){
    //                 return bankStorage1d[hashvalue].balance;
    //                 break;
    //             }
                
    //         }
    //         // else if(hashvalue==99999){
    //         //     hashvalue=(hashvalue+(kk**2))%100000;
    //         //     if(bankStorage1d[hashvalue].id==""){
    //         //         bankStorage1d[hashvalue]=Accounti;
    //         //     }
    //         // }
    // }
    int hashvalue=hash(id);
    int poppy=hashvalue-1;
    if(bankStorage1d[hashvalue].id==id){
        return bankStorage1d[hashvalue].balance;
    }
    else {
        while(bankStorage1d[hashvalue].id!=id){
            if(hashvalue==poppy){
                return -1;
            }



            else if(hashvalue!=99999){
                hashvalue=hashvalue+1;
                if(bankStorage1d[hashvalue].id==id){
                    return bankStorage1d[hashvalue].balance;
                }
            }
            else if(hashvalue==99999){
                hashvalue=0;
                if(bankStorage1d[hashvalue].id==id){
                    return bankStorage1d[hashvalue].balance;
                }
            }
            
        }
    }
    
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    // hashvalue=hash(id);
    // if(bankStorage1d[hashvalue].id==id){
    //     bankStorage1d[hashvalue].balance=bankStorage1d[hashvalue].balance+count;
    // }
    // else {
    //     while(bankStorage1d[hashvalue].id!=id){
            
    //             kk=kk+1;
    //             hashvalue=(hashvalue+(kk**2))%100000;
                
    //             if(bankStorage1d[hashvalue].id==id){
    //                 bankStorage1d[hashvalue].balance += count;
    //                 break;
    //             }
                
    //         }
    //         // else if(hashvalue==99999){
    //         //     hashvalue=(hashvalue+(kk**2))%100000;
    //         //     if(bankStorage1d[hashvalue].id==""){
    //         //         bankStorage1d[hashvalue]=Accounti;
    //         //     }
    //         // }
    // }
    int hashvalue=hash(id);
    int poppy=hashvalue-1;
    if(bankStorage1d[hashvalue].id==id){
        bankStorage1d[hashvalue].balance=bankStorage1d[hashvalue].balance+count;
    }
    else {
        while(bankStorage1d[hashvalue].id!=id){
            if(hashvalue==poppy){
                createAccount(id,count);
            }
            if(hashvalue!=99999){
                hashvalue=hashvalue+1;
                if(bankStorage1d[hashvalue].id==id){
                    bankStorage1d[hashvalue].balance=bankStorage1d[hashvalue].balance+count;
                }
            }
            else if(hashvalue==99999){
                hashvalue=0;
                if(bankStorage1d[hashvalue].id==id){
                    bankStorage1d[hashvalue].balance=bankStorage1d[hashvalue].balance+count;
                }
            }
        }
    }
}

bool QuadraticProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int hashvalue=hash(id);
    int gapple=hashvalue-1;
    if(bankStorage1d[hashvalue].id==id){
        return true;
    }
    else {
        while(bankStorage1d[hashvalue].id!=id){
            
            if(hashvalue!=99999 && hashvalue!=gapple){
                hashvalue=hashvalue+1;
                if(bankStorage1d[hashvalue].id==id){
                    return true;
                    break;
                }
            }
            else if(hashvalue==99999){
                hashvalue=0;
                if(bankStorage1d[hashvalue].id==id){
                    return true;
                    break;
                }
            }
            else if(hashvalue==gapple){
                return false;
                break;
            }
        }
    }
}

bool QuadraticProbing::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    
    int hashvalue=hash(id);
    int gapple=hashvalue-1;
    if(bankStorage1d[hashvalue].id==id){
        // bankStorage1d.erase(bankStorage1d.begin() + hashvalue);
        bankStorage1d[hashvalue].id="";
        bankStorage1d[hashvalue].balance=0;
        syze=syze-1;
        return true;
    }
    else {
        while(bankStorage1d[hashvalue].id!=id){
            
            if(hashvalue!=99999 && hashvalue!=gapple){
                hashvalue=hashvalue+1;
                if(bankStorage1d[hashvalue].id==id){
                    // bankStorage1d.erase(bankStorage1d.begin() + hashvalue);
                    bankStorage1d[hashvalue].id="";
                    bankStorage1d[hashvalue].balance=0;
                    syze=syze-1;
                    return true;
                }
            }
            else if(hashvalue==99999){
                hashvalue=0;
                if(bankStorage1d[hashvalue].id==id){
                    // bankStorage1d.erase(bankStorage1d.begin() + hashvalue);
                    bankStorage1d[hashvalue].id="";
                    bankStorage1d[hashvalue].balance=0;
                    syze=syze-1;
                    return true;
                }
            }
            else if(hashvalue==gapple){
                return false;
            }
        }
    }
    // Placeholder return value
}
int QuadraticProbing::databaseSize() {
    
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
    
    return syze;
}

int QuadraticProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int len;
    
    int hashval;
    len = id.length();
    int i=1;
    while(i<len){
        // hashval=hashval + powpow((int(id[i])-int(id[i-1])),2)*(powpow(37,i));
        hashval=int(id[i])*int(id[i])*int(id[i]);
        i++;
    }
    hashval=hashval%100000;
    return hashval;

     // Placeholder return value
}
