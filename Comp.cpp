#include "Comp.h"
#include <vector>
using namespace std;
int hash2(std::string id){
	int len;
    
    int hashval;
    len = id.length();
    int i=1;
    while(i<len){
        // hashval=hashval + powpow((int(id[i])-int(id[i-1])),2)*(powpow(37,i));
        hashval=int(id[i])*int(id[i])*int(id[i])*int(id[i]);
        i++;
    }
    hashval=hashval%99371;
    return hashval;
}
void Comp::createAccount(std::string id, int count) {
    syze++;
    Account Accounti;
    Accounti.id=id;
    Accounti.balance=count;       
    int hashvalue=hash(id);
    //99371
    if(bankStorage1d[hashvalue].id==""){
        bankStorage1d[hashvalue]=Accounti;
    }
    else{
    	while(bankStorage1d[hashvalue].id!=""){
	    	hashvalue=hashvalue+hash2(id);
	    	hashvalue=hashvalue%100000;
	    	if(bankStorage1d[hashvalue].id==""){
        		bankStorage1d[hashvalue]=Accounti;
        		break;
    		}
	    	
    }
    }
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
std::vector<int> Comp::getTopK(int k) {
    // std::vector<int> green;
    // for(int i=0;i<k;i++){
    //     int max=bankStorage1d[0].balance;
    //     for(int j=0;j<100000;j++){
    //         if (bankStorage1d[j].balance>max && i>0 && bankStorage1d[j].balance<green[i-1]){
    //             max=bankStorage1d[j].balance;
    //         }
    //         else if(bankStorage1d[j].balance>max && i==0){
    //             max=bankStorage1d[j].balance;
    //         }

    //     }
    //     green.push_back(max);
    // }
    // return green;
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

int Comp::getBalance(std::string id) {
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

void Comp::addTransaction(std::string id, int count) {
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

bool Comp::doesExist(std::string id) {
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

bool Comp::deleteAccount(std::string id) {
    
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

}
int Comp::databaseSize() {
    return syze;
}

int Comp::hash(std::string id) {
    int len;
    
    long long int hashval=0;
    len = id.length();
    int i=1;
    while(i<len){
        // hashval=hashval + powpow((int(id[i])-int(id[i-1])),2)*(powpow(37,i));
        hashval=int(id[i])*int(id[i])*int(id[i]);
        i++;
    }
    hashval=hashval%100000;
    return hashval;

}


// Feel free to add any other helper functions you need
// Good Luck!
