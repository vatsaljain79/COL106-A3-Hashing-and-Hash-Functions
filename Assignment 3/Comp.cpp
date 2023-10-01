#include "Comp.h"
#include <vector>
using namespace std;

Comp::Comp(){
    Account myacc;
    myacc.id="ok";
    myacc.balance=-1;
    bankStorage1d = vector<Account>(110069,myacc);
}

void Merg(vector<int>& v, int a, int b, int c) {
	
	vector<int> help;

	int i, j;
	i = a;
	j = b + 1;

	while (i <= b && j <= c) {

		if (v[i] <= v[j]) {
			help.push_back(v[i]);
			++i;
		}
		else {
			help.push_back(v[j]);
			++j;
		}

	}

	while (i <= b) {
		help.push_back(v[i]);
		++i;
	}

	while (j <= c) {
		help.push_back(v[j]);
		++j;
	}

	for (int i = a; i <= c; ++i)
		v[i] = help[i - a];

}


void MergeSort(vector<int>& v, int a, int b) {
	if (a < b) {
		int m = (a + b) / 2;
		MergeSort(v, a, m);
		MergeSort(v, m + 1, b);
		Merg(v, a, m, b);
	}
}

void Comp::createAccount(std::string id, int count) {
    
    Account myacc;
    myacc.id=id;
    myacc.balance=count;
    int hashindex=hash(id);
    int probe=hashindex;
    int collision=0;
    while (bankStorage1d[probe].balance!=-1){
        if (bankStorage1d[probe].balance==-2){
            break;
        }
        collision++;
        probe =hashindex+(collision*collision*collision);
        if (probe>=110069){
            probe=probe%110069;
        }
    }
    bankStorage1d[probe]=myacc;
    sizee++;
    indices.push_back(probe);
    // cout<<probe<<endl;
    // topbalances.push_back(count);
    // IMPLEMENT YOUR CODE HERE
}

std::vector<int> Comp::getTopK(int k) {
    int i, j, min, temp;
    vector<int>topbalances;
    // cout<<"qw";
    for (int p=0;p<indices.size();p++){
        
        int b=bankStorage1d[indices[p]].balance;
        // cout<<b;
        if (b>=0){
            topbalances.push_back(b);
            // cout<<b<<endl;
        }
    }
    // cout<<"qw";
    int n=topbalances.size();
    // cout<<"n: "<<n<</endl;
   
//    for (i = 0; i < n - 1; i++) {
//       min = i;
//       for (j = i + 1; j < n; j++)
//       if (topbalances[j] < topbalances[min])
//       min = j;
//       temp = topbalances[i];
//       topbalances[i] = topbalances[min];
//       topbalances[min] = temp;
//    }
MergeSort(topbalances,0,n-1);
// cout<<"qw";
    // reverse (topbalances.begin(),topbalances.end());
    vector <int> ans;
    int idx=sizee-1;
    // cout<<"Size "<<size<<endl;
    // cout<<topbalances.size()<<endl;
    // cout<<topbalances[0]<<" "<<" "<<topbalances[1]<<" "<<topbalances[2]<<" "<<topbalances[3]<<" "<<topbalances[4]<<" "<<topbalances[5]<<endl;
    while (k>0){
        ans.push_back(topbalances[idx]);
        // idx++;
        idx--;
        k--;
    }
    // cout<<"size: "<<ans.size();
    // cout<<"qwuy";
    // IMPLEMENT YOUR CODE HERE
    return ans;
    // IMPLEMENT YOUR CODE HERE
    // return std::vector<int>(); // Placeholder return value
}

int Comp::getBalance(std::string id) {
     int hashindex=hash(id);
    int b=-1;
    int probe=hashindex;
    int collision=0;
    while (bankStorage1d[probe].balance!=-1){
        collision++;
        if (bankStorage1d[probe].id==id){
            b=bankStorage1d[probe].balance;
            break;
        }
        probe =hashindex+(collision*collision*collision);
        if (probe>=110069){
            probe=probe%110069;
        }
    }
    // IMPLEMENT YOUR CODE HERE
    return b;
    // IMPLEMENT YOUR CODE HERE
    // return 0; // Placeholder return value
}

void Comp::addTransaction(std::string id, int count) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    int probe=hashindex;
    int collision=0;
    while (bankStorage1d[probe].balance!=-1){
        collision++;
        if (bankStorage1d[probe].id==id){
            // int aw=bankStorage1d[probe].balance;
            // for (int j=0;j<topbalances.size();j++){
            //     if (topbalances[j]==aw){
            //         topbalances.erase(topbalances.begin()+j);
            //         break;
            //     }
            // }
            bankStorage1d[probe].balance+=count;
            // int awq=bankStorage1d[probe].balance;
            // topbalances.push_back(awq);
            got=true;
            break;
        }
        probe =hashindex+(collision*collision*collision);
        if (probe>=110069){
            probe=probe%110069;
        }
    }
    if (got==false){
        createAccount(id,count);
    }
    // IMPLEMENT YOUR CODE HERE
}

bool Comp::doesExist(std::string id) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    int probe=hashindex;
    int collision=0;
    while (bankStorage1d[probe].balance!=-1){
        collision++;
        if (bankStorage1d[probe].id==id){
            // int aw=bankStorage1d[probe].balance;
            // bankStorage1d[probe].balance+=count;
            got=true;
            break;
        }
        probe =hashindex+(collision*collision*collision);
        if (probe>=110069){
            probe=probe%110069;
        }
    }
    // IMPLEMENT YOUR CODE HERE
    return got;
    // IMPLEMENT YOUR CODE HERE
    // return false; // Placeholder return value
}

bool Comp::deleteAccount(std::string id) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    int probe=hashindex;
    int collision=0;
    while (bankStorage1d[probe].balance!=-1){
        collision++;
        if (bankStorage1d[probe].id==id){
            
            // int aw=bankStorage1d[probe].balance;
            // bankStorage1d[probe].balance+=count;
            // int aw=bankStorage1d[probe].balance;
            // for (int j=0;j<topbalances.size();j++){
            //     if (topbalances[j]==aw){
            //         topbalances.erase(topbalances.begin()+j);
            //         break;
            //     }
            // }
            bankStorage1d[probe].balance=-2;
            bankStorage1d[probe].id="ok";
            got=true;
            sizee-=1;
            break;
        }
        probe =hashindex+(collision*collision*collision);
        if (probe>=110069){
            probe=probe%110069;
        }
    }
    // IMPLEMENT YOUR CODE HERE
    return got;
    // IMPLEMENT YOUR CODE HERE
    // return false; // Placeholder return value
}
int Comp::databaseSize() {
    return sizee;
    // IMPLEMENT YOUR CODE HERE
    // return 0; // Placeholder return value
}

int Comp::hash(std::string id) {
    double ascii=0;
    int n=21;
    double a=1.3;
    double c=1;
    int idx=0;
    while (n>=0){
        
        if (int(id[n])<58 && int(id[n])>46){
            int b=int(id[n]);
            if (n!=21){
                c=c*a*a;
            }
            ascii+=c*b;
            idx++;
        }
        else if (int(id[n])!=95){
            int b=int(id[n]);
            
            c=c*a*a;
            ascii+=c*b;
            idx++;
        }
        
        n--;
        
    }
    return (int)ascii%110069;
    // IMPLEMENT YOUR CODE HERE
    // return 0; // Placeholder return value
}
// int main(){
//     Comp db;
// // // // // //     // cout<<"qwe";
//     cout<<db.databaseSize()<<endl;
// // db.createAccount("ABCD1234567_1234567890", 1000);
// // // // cout<<(db.getBalance("ABCD1234567_1234567890") );
//     db.createAccount("ABCD1234567_1234567895",1500);
//     db.createAccount("ABCD1234567_1234567891",1900);
//     db.createAccount("ABCD1234567_1234567898",1700);
//     db.createAccount("ABCD1234567_1234567899",1300);
// // //     db.addTransaction("ABCD1234567_1234567892",1900);
// // //     // db.addTransaction("ABCD1234567_1234567892",1900);
    
// //     cout<<db.getBalance("ABCD1234567_1234567891")<<endl;
    
//     cout<<db.deleteAccount("ABCD1234567_1234567891")<<endl;
//     cout<<db.deleteAccount("ABCD1234567_1234567895")<<endl;
// //     cout<<db.doesExist("ABCD1234567_123456791")<<endl;
// //     cout<<db.getBalance("ABCD1234567_1234567890")<<endl;
//     // cout<<"hiii";
//     vector<int>arrr=db.getTopK(3);
//     for (int i=0;i<arrr.size();i++){
//         cout<<arrr[i]<<" ";
//     }
// // //     cout<<endl;
// // // //     cout<<db.databaseSize()<<endl;
//     return 0 ;
// }

