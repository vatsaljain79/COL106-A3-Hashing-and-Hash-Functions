#include "Chaining.h"
#include <vector>
// #include <string>
using namespace std;

Chaining::Chaining(){
    
    bankStorage2d = vector<vector<Account>>(110069);}

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

void Chaining::createAccount(std::string id, int count) {
    
    if (sizee==0){
        // cout<<"pagal";
    bankStorage2d = vector<vector<Account>>(110069);}
    Account myacc;
    myacc.id=id;
    myacc.balance=count;
    // cout<<"pagal";
    int hashindex=hash(id);
    // cout<<"pagal";
    bankStorage2d[hashindex].push_back(myacc);
    sizee+=1;
    
    topbalances.push_back(count);
    // int idx=0;
    // while (idx<topbalances.size()){
    //     if (topbalances[idx]>count){
    //         idx++;
    //     }
    //     else{
    //         break;
    //     }
    //     // idx++;
    // }
    // topbalances.insert(topbalances.begin()+idx,count);
    // IMPLEMENT YOUR CODE HERE
}

std::vector<int> Chaining::getTopK(int k) {
    int i, j, min, temp;
    int n=topbalances.size();
   
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
    
    // IMPLEMENT YOUR CODE HERE
    return ans; // Placeholder return value
}

int Chaining::getBalance(std::string id) {
    int hashindex=hash(id);
    int b=-1;
    for (int i=0;i<bankStorage2d[hashindex].size();i++){
        if (bankStorage2d[hashindex][i].id==id){
            b=bankStorage2d[hashindex][i].balance;
            break;
        }  
    }
    return b;

    // IMPLEMENT YOUR CODE HERE
    // return 0; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    for (int i=0;i<bankStorage2d[hashindex].size();i++){
        if (bankStorage2d[hashindex][i].id==id){
            int aw=bankStorage2d[hashindex][i].balance;
            for (int j=0;j<topbalances.size();j++){
                if (topbalances[j]==aw){
                    topbalances.erase(topbalances.begin()+j);
                    break;
                }
            }
            bankStorage2d[hashindex][i].balance+=count;
            int awq=bankStorage2d[hashindex][i].balance;
            topbalances.push_back(awq);
            got=true;
            break;
        }  
    }
    if (got==false){
        createAccount(id,count);
        // topbalances.push_back(count);
    }
    // IMPLEMENT YOUR CODE HERE
}

bool Chaining::doesExist(std::string id) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    for (int i=0;i<bankStorage2d[hashindex].size();i++){
        if (bankStorage2d[hashindex][i].id==id){
            got=true;
            break;
        }  
    }
    return got;

    // IMPLEMENT YOUR CODE HERE
    // return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    int hashindex=hash(id);
    // int b=-1;
    bool got=false;
    for (int i=0;i<bankStorage2d[hashindex].size();i++){
        if (bankStorage2d[hashindex][i].id==id){
            int aw=bankStorage2d[hashindex][i].balance;
            for (int j=0;j<topbalances.size();j++){
                if (topbalances[j]==aw){
                    topbalances.erase(topbalances.begin()+j);
                    break;
                }
            }
            bankStorage2d[hashindex].erase(bankStorage2d[hashindex].begin()+i);
            got=true;
            sizee-=1;
            break;
        }  
    }
    
    return got;
    // IMPLEMENT YOUR CODE HERE
    // return false; // Placeholder return value
}
int Chaining::databaseSize() {
    return sizee;
    // IMPLEMENT YOUR CODE HERE
    // return 0; // Placeholder return value
}

int Chaining::hash(std::string id) {
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
//     Chaining db;
// // // //     // cout<<"qwe";
// // // //     // cout<<db.databaseSize()<<endl;
// db.createAccount("ABCD1234567_1234567890", 1000);
// // // cout<<(db.getBalance("ABCD1234567_1234567890") );
//     db.createAccount("ABCD1234567_1234567895",1500);
//     db.createAccount("ABCD1234567_1234567891",1900);
//     db.createAccount("ABCD1234567_1234567898",1700);
// //     db.createAccount("ABCD1234567_1234567899",1300);
// //     db.addTransaction("ABCD1234567_1234567892",1900);
// //     // db.addTransaction("ABCD1234567_1234567892",1900);
    
//     cout<<db.getBalance("ABCD1234567_1234567891")<<endl;
    
//     cout<<db.deleteAccount("ABCD1234567_1234567891")<<endl;
//     cout<<db.doesExist("ABCD1234567_123456791")<<endl;
//     cout<<db.getBalance("ABCD1234567_1234567890")<<endl;
// // //     // cout<<"hiii";
//     vector<int>arrr=db.getTopK(3);
//     for (int i=0;i<arrr.size();i++){
//         cout<<arrr[i]<<" ";
//     }
// //     cout<<endl;
// // //     cout<<db.databaseSize()<<endl;
//     return 0 ;
// }

