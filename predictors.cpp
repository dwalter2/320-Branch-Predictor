#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <math.h>
#include <bitset>
#include <utility>

using namespace std;

vector<int> alwaysTaken(vector<string> b){
	int sum = 0;
	int total = 0;
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i]=="T"){
			sum++;
		}
		total++;
	}
	vector<int> ret;
	ret.push_back(sum);
	ret.push_back(total);
	return ret;
};

vector<int> alwaysNotTaken(vector<string> b){
	int sum = 0;
	int total = 0;
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i]=="NT"){
			sum++;
		}
		total++;
	}
	vector<int> ret;
	ret.push_back(sum);
	ret.push_back(total);
	return ret;
};

vector<int> biModelSingle(vector<unsigned long long> a, vector<string> b){
	vector<int> ret;
	unsigned long long addr;
  	string behavior;
	unsigned long long target;
	vector<string> sixteenbit;
	sixteenbit.resize(16);
	vector<string> thirtytwobit;
	thirtytwobit.resize(32);
	vector<string> onetwoeightbit;
	onetwoeightbit.resize(128);
	vector<string> twofivesixbit;
	twofivesixbit.resize(256);
	vector<string> fivetwelvebit;
	fivetwelvebit.resize(512);
	vector<string> ten24bit;
	ten24bit.resize(1024);
	vector<string> twenty48bit;
	twenty48bit.resize(2048);
	for(int i = 0 ; i < 2048 ; i++){
		if(i < sixteenbit.size()){
			sixteenbit[i]="T";
		}
		if(i < thirtytwobit.size()){
			thirtytwobit[i]="T";
		}
		if(i < onetwoeightbit.size()){
			onetwoeightbit[i]="T";
		}
		if(i < twofivesixbit.size()){
			twofivesixbit[i]="T";
		}
		if(i < fivetwelvebit.size()){
			fivetwelvebit[i]="T";
		}
		if(i < ten24bit.size()){
			ten24bit[i]="T";
		}
		if(i < twenty48bit.size()){
			twenty48bit[i]="T";
		}
	}
	int sum16 = 0;
	int total16 = 0;
	for(int i = 0 ; i < a.size() ; i++){
		int index16bit = a[i]%16;
		if(sixteenbit[index16bit]==b[i]){
			sum16++;
		}
		else{
			if(b[i]=="T"){
				sixteenbit[index16bit]="T";
			}
			else{
				sixteenbit[index16bit]="NT";
			}
		}
		total16++;
	}
	ret.push_back(sum16);
	ret.push_back(a.size());
	long sum32 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index32bit = a[i]%32;
		if(thirtytwobit[index32bit]==b[i]){
			sum32++;
		}
		else{
			if(b[i]=="T"){
				thirtytwobit[index32bit]="T";
			}
			else{
				thirtytwobit[index32bit]="NT";
			}
		}
	}
	ret.push_back(sum32);
	ret.push_back(a.size());
	long sum128 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index128bit = a[i]%128;
		if(onetwoeightbit[index128bit]==b[i]){
			sum128++;
		}
		else{
			if(b[i]=="T"){
				onetwoeightbit[index128bit]="T";
			}
			else{
				onetwoeightbit[index128bit]="NT";
			}
		}
	}
	ret.push_back(sum128);
	ret.push_back(a.size());
	long sum256 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index256bit = a[i]%256;
		if(twofivesixbit[index256bit]==b[i]){
			sum256++;
		}
		else{
			if(b[i]=="T"){
				twofivesixbit[index256bit]="T";
			}
			else{
				twofivesixbit[index256bit]="NT";
			}
		}
	}
	ret.push_back(sum256);
	ret.push_back(a.size());
	long sum512 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index512bit = a[i]%512;
		if(fivetwelvebit[index512bit]==b[i]){
			sum512++;
		}
		else{
			if(b[i]=="T"){
				fivetwelvebit[index512bit]="T";
			}
			else{
				fivetwelvebit[index512bit]="NT";
			}
		}
	}
	ret.push_back(sum512);
	ret.push_back(a.size());
	long sum1024 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index1024bit = a[i]%1024;
		if(ten24bit[index1024bit]==b[i]){
			sum1024++;
		}
		else{
			if(b[i]=="T"){
				ten24bit[index1024bit]="T";
			}
			else{
				ten24bit[index1024bit]="NT";
			}
		}
	}
	ret.push_back(sum1024);
	ret.push_back(a.size());
	long sum2048 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index2048bit = a[i]%2048;
		if(twenty48bit[index2048bit]==b[i]){
			sum2048++;
		}
		else{
			if(b[i]=="T"){
				twenty48bit[index2048bit]="T";
			}
			else{
				twenty48bit[index2048bit]="NT";
			}
		}
	}
	ret.push_back(sum2048);
	ret.push_back(a.size());
	return ret;
};

vector<int> biModelTwoBit(vector<unsigned long long> a , vector<string> b){
	vector<int> ret;
	vector<int> sixteenbit;
	sixteenbit.resize(16);
	vector<int> thirtytwobit;
	thirtytwobit.resize(32);
	vector<int> onetwoeightbit;
	onetwoeightbit.resize(128);
	vector<int> twofivesixbit;
	twofivesixbit.resize(256);
	vector<int> fivetwelvebit;
	fivetwelvebit.resize(512);
	vector<int> ten24bit;
	ten24bit.resize(1024);
	vector<int> twenty48bit;
	twenty48bit.resize(2048);
	for(int i = 0 ; i < 2048 ; i++){
		if(i < sixteenbit.size()){
			sixteenbit[i]=3;
		}
		if(i < thirtytwobit.size()){
			thirtytwobit[i]=3;
		}
		if(i < onetwoeightbit.size()){
			onetwoeightbit[i]=3;
		}
		if(i < twofivesixbit.size()){
			twofivesixbit[i]=3;
		}
		if(i < fivetwelvebit.size()){
			fivetwelvebit[i]=3;
		}
		if(i < ten24bit.size()){
			ten24bit[i]=3;
		}
		if(i < twenty48bit.size()){
			twenty48bit[i]=3;
		}
	}
	int sum16 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%16;
		if(b[i]=="T"&&sixteenbit[index]>=2){
			if(sixteenbit[index]==2){
				sixteenbit[index]=3;
			}
			sum16++;
		}
		else if(b[i]=="T"&&sixteenbit[index]<2){
			sixteenbit[index]++;
		}
		else if(b[i]=="NT"&&sixteenbit[index]>=2){
			sixteenbit[index]--;
		}
		else{
			if(sixteenbit[index]==1){
				sixteenbit[index]--;
			}
			sum16++;
		}
	}
	ret.push_back(sum16);
	ret.push_back(a.size());
	int sum32 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%32;
		if(b[i]=="T"&&thirtytwobit[index]>=2){
			if(thirtytwobit[index]==2){
				thirtytwobit[index]=3;
			}
			sum32++;
		}
		else if(b[i]=="T"&&thirtytwobit[index]<2){
			thirtytwobit[index]++;
		}
		else if(b[i]=="NT"&&thirtytwobit[index]>=2){
			thirtytwobit[index]--;
		}
		else{
			if(thirtytwobit[index]==1){
				thirtytwobit[index]--;
			}
			sum32++;
		}
	}
	ret.push_back(sum32);
	ret.push_back(a.size());
	int sum128 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%128;
		if(b[i]=="T"&&onetwoeightbit[index]>=2){
			if(onetwoeightbit[index]==2){
				onetwoeightbit[index]=3;
			}
			sum128++;
		}
		else if(b[i]=="T"&&onetwoeightbit[index]<2){
			onetwoeightbit[index]++;
		}
		else if(b[i]=="NT"&&onetwoeightbit[index]>=2){
			onetwoeightbit[index]--;
		}
		else{
			if(onetwoeightbit[index]==1){
				onetwoeightbit[index]--;
			}
			sum128++;
		}
	}
	ret.push_back(sum128);
	ret.push_back(a.size());
	int sum256 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%256;
		if(b[i]=="T"&&twofivesixbit[index]>=2){
			if(twofivesixbit[index]==2){
				twofivesixbit[index]=3;
			}
			sum256++;
		}
		else if(b[i]=="T"&&twofivesixbit[index]<2){
			twofivesixbit[index]++;
		}
		else if(b[i]=="NT"&&twofivesixbit[index]>=2){
			twofivesixbit[index]--;
		}
		else{
			if(twofivesixbit[index]==1){
				twofivesixbit[index]--;
			}
			sum256++;
		}
	}
	ret.push_back(sum256);
	ret.push_back(a.size());
	int sum512 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%512;
		if(b[i]=="T"&&fivetwelvebit[index]>=2){
			if(fivetwelvebit[index]==2){
				fivetwelvebit[index]=3;
			}
			sum512++;
		}
		else if(b[i]=="T"&&fivetwelvebit[index]<2){
			fivetwelvebit[index]++;
		}
		else if(b[i]=="NT"&&fivetwelvebit[index]>=2){
			fivetwelvebit[index]--;
		}
		else{
			if(fivetwelvebit[index]==1){
				fivetwelvebit[index]--;
			}
			sum512++;
		}
	}
	ret.push_back(sum512);
	ret.push_back(a.size());
	int sum1024 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%1024;
		if(b[i]=="T"&&ten24bit[index]>=2){
			if(ten24bit[index]==2){
				ten24bit[index]=3;
			}
			sum1024++;
		}
		else if(b[i]=="T"&&ten24bit[index]<2){
			ten24bit[index]++;
		}
		else if(b[i]=="NT"&&ten24bit[index]>=2){
			ten24bit[index]--;
		}
		else{
			if(ten24bit[index]==1){
				ten24bit[index]--;
			}
			sum1024++;
		}
	}
	ret.push_back(sum1024);
	ret.push_back(a.size());
	int sum2048 = 0;
	for(int i = 0 ; i < b.size() ; i++){
		int index = a[i]%2048;
		if(b[i]=="T"&&twenty48bit[index]>=2){
			if(twenty48bit[index]==2){
				twenty48bit[index]=3;
			}
			sum2048++;
		}
		else if(b[i]=="T"&&twenty48bit[index]<2){
			twenty48bit[index]++;
		}
		else if(b[i]=="NT"&&twenty48bit[index]>=2){
			twenty48bit[index]--;
		}
		else{
			if(twenty48bit[index]==1){
				twenty48bit[index]--;
			}
			sum2048++;
		}
	}
	ret.push_back(sum2048);
	ret.push_back(a.size());
	return ret;

};

int gShare(vector<unsigned long long> a , vector<string> b, int bitsize){
	unsigned long size = (int) pow(2,bitsize)-1;
	unsigned int correct = 0;
	unsigned int gr = 0;
	vector<int> table;
	for(int i = 0 ; i < 2048 ; i++){
		table.push_back(3);
	}
	for(int i = 0 ; i < a.size() ; i++){
		int index = (a[i] ^ (gr & size)) % 2048;
		if(b[i]=="T"){
			if(table[index]>=2){
				if(table[index]==2){
					table[index]++;
				}
				correct++;
			}
			else{
				table[index]++;
			}
		}
		else{
			if(table[index]<2){
				if(table[index]==1){
					table[index]--;
				}
				correct++;
			}
			else{
				table[index]--;
			}
		}
		int branchoutcome = 0;
		if(b[i]=="T"){
			branchoutcome=1;
		}
		gr = gr << 1;
		gr = gr | branchoutcome;
	}
	return correct;
};

int Tournament(vector<unsigned long long> a , vector<string> b){
	vector<int> gtable(2048, 3);
	vector<int> btable(2048, 3);
	vector<int> stable(2048, 0);
	unsigned long size = (int) pow(2,11)-1;
	unsigned int correct = 0;
	unsigned int gr = 0;
	for(int i = 0 ; i < a.size() ; i++){
		bool bcorrect = false;
		int bindex = a[i]%2048;
		if(b[i]=="T"&&btable[bindex]>=2){
			if(btable[bindex]==2){
				btable[bindex]++;
			}
			bcorrect = true;
		}
		else if(b[i]=="T"&&btable[bindex]<2){
			btable[bindex]++;
		}
		else if(b[i]=="NT"&&btable[bindex]>=2){
			btable[bindex]--;
		}
		else{
			if(btable[bindex]==1){
				btable[bindex]--;
			}
			bcorrect=true;
		}
		bool gcorrect = false;
		int gindex = (a[i] ^ (gr & size)) % 2048;
		if(b[i]=="T"){
			if(gtable[gindex]>=2){
				if(gtable[gindex]==2){
					gtable[gindex]++;
				}
				gcorrect=true;
			}
			else{
				gtable[gindex]++;
			}
		}
		else{
			if(gtable[gindex]<2){
				if(gtable[gindex]==1){
					gtable[gindex]--;
				}
				gcorrect=true;
			}
			else{
				gtable[gindex]--;
			}
		}
		int branchoutcome = 0;
		if(b[i]=="T"){
			branchoutcome=1;
		}
		gr = gr << 1;
		gr = gr | branchoutcome;
		int state = stable[bindex];
		if(bcorrect==gcorrect){
			if(bcorrect==true){
				//cout << " both correct " ;
				correct++;
			}
		}
		else{
					//cout << "state prior: " << state;

			if(state>=2){
				//choose bimodel
				if(bcorrect==true){
				//	cout << " bimodel chosen and correct ";
					//bimodel right
					if(state==2){
						state++;
					}
					correct++;
				}
				else{
					//cout << " bimodel wrong ";
					//bimodel wrong
					state--;
				}
			}
			else{
				//cout << "state: " << state;
				//cout << "state if gshare chosen: " << state;
				//choose gshare
				//cout << " gcorrect?: " << gcorrect << endl;
				if(gcorrect==true){
					//cout << " gshare correct ";
					//gshare right
					if(state==1){
						state--;
					}
					correct++;
				}
				else{
					//cout << " gshare wrong ";
					//gshare wrong
					state++;
				}
			}
									//cout << " state after: " << state << endl;

		}
		stable[bindex]=state;
		/*if(gcorrect==true&&bcorrect==true){
			correct++;
		}
		else if(gcorrect==true&&bcorrect==false){
			if(counter<=1){
				if(counter==1){
					counter--;
				}
				correct++;
			}
			else{
				cout << "i : " << i << endl;
				cout << "miss, gcorrect: " << gcorrect << " bcorrect : " << bcorrect << endl;
				counter--;
				cout << "counter : " << counter << endl;
			}
		}
		else if(gcorrect==false&&bcorrect==true){
			cout << "bcorrect > gcorrect" << endl;
			if(counter>=2){
				if(counter==2){
					counter++;
				}
				correct++;
			}
			else{
				counter++;
			}
		}*/
	}
	return correct;
};

vector<int> btb(vector<unsigned long long> a, vector<string> b, vector<unsigned long long> t){
	vector<int> btable (512,1);
	unsigned int branches = 0;
	unsigned int hits = 0;
	vector<int> ret;
	vector<pair<unsigned long long, unsigned long long>> targets;
	for(int i = 0 ; i < 128 ; i++){
		targets.push_back(pair <unsigned long long, unsigned long long> (0,0));
	}
	for(int i = 0 ; i < a.size() ; i++){
		int targetindex = a[i]%128;
		int index512bit = a[i]%512;
		if(btable[index512bit]==1){
			branches++;
			if(targets[targetindex].first==a[i]){
				if(targets[targetindex].second==t[i]){
					hits++;
				}
			}
			else{
				targets[targetindex]=pair <unsigned long long, unsigned long long> (a[i],t[i]);
			}
		}
		string behave = "NT";
		if(btable[index512bit]==1){
			behave="T";
		}
		if(behave!=b[i]){
			if(b[i]=="T"){
				btable[index512bit]=1;
			}
			else{
				btable[index512bit]=0;
			}
		}
		
	}
	ret.push_back(branches);
	ret.push_back(hits);
	return ret;
};

int main(int argc, char *argv[]){
	unsigned long long addr;
	string behavior;
	unsigned long long target;
	vector<unsigned long long> addresses;
	vector<string> behaviors;
	vector<unsigned long long> targets;
	ofstream output;
	output.open(argv[2]);
  	// Open file for reading
  	ifstream infile(argv[1]);
	//infile.open()
  	// The following loop will read a hexadecimal number and
  	// a string each time and then output them
  	while(infile >> std::hex >> addr >> behavior >> std::hex >> target) {
		//cout << addr << endl;
    		addresses.push_back(addr);
		behaviors.push_back(behavior);
		targets.push_back(target);
  	}
	vector<int> retval;
	retval = alwaysTaken(behaviors);
	output << retval[0] << "," << retval[1] << endl;
	vector<int> retval2;
	retval2 = alwaysNotTaken(behaviors);
	output << retval2[0] << "," << retval2[1] << endl;
	vector<int> retval3;
	retval3 = biModelSingle(addresses, behaviors);
	for(int i= 0 ; i < retval3.size() ; i++){
		if(i!=retval3.size()-1&&i%2==0){
			output << retval3[i] << ",";
		}
		else{
			output << retval3[i];
		}
		if(i%2==1){
			output << "; ";
		}
	}
	output << endl;
	vector<int> retval4;
	retval4 = biModelTwoBit(addresses, behaviors);
	for(int i= 0 ; i < retval4.size() ; i++){
		if(i!=retval4.size()-1&&i%2==0){
			output << retval4[i] << ",";
		}
		else{
			output << retval4[i];
		}
		if(i%2==1){
			output << "; ";
		}
	}
	output << endl;
	vector<int> retval5;
	for(int i = 3 ; i < 12 ; i++){
		retval5.push_back(gShare(addresses, behaviors , i));
	}
	for(int i = 0 ; i < retval5.size() ; i++){
		output << retval5[i] << "," << addresses.size() << ";";
	}
	output<< endl;
	int retval6 = Tournament(addresses, behaviors);
	output << retval6 << "," << addresses.size() << ";" << endl;
	vector<int> retval7 = btb(addresses,behaviors,targets);
	output << retval7[0] <<"," << retval7[1] <<";" << endl;
	infile.close();
	output.close();
}
