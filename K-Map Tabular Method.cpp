#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Erasing_duplicates(vector<int>& min_terms)
{
	//checking for dublicates and erasing them: *(only works if the min_terms are sorted ascendingly)
	int counter = 0;     // to determine whether or not to display the next message in the code
	for (size_t i = 0; i < min_terms.size() - 1; i++)
	{
		if (min_terms[i] == min_terms[i + 1])
		{
			min_terms.erase(min_terms.begin() + i);
			i--;
			counter++;
		}
	}
	if (counter > 0)
	{
		cout << "\nThe minterms entered had " << counter << " duplicates, and they have been erased";
		cout << "\nThe minterms now are:\n";
		for (size_t i = 0; i < min_terms.size(); i++)
			cout << min_terms[i] << endl;
	}
}

void Printing_kmap(vector<int> min_terms, int size)     //for generating the K-map
{
	int*arr = new int[8];
	for (size_t i = 0; i < size; i++)
	{
		if (min_terms[i] == 2 || min_terms[i] == 6)
			arr[min_terms[i] + 1] = 1;
		
		else if (min_terms[i] == 3 || min_terms[i] == 7)
			arr[min_terms[i] - 1] = 1;
		
		else
			arr[min_terms[i]] = 1;
	}
		

	for (size_t i = 0; i < 8; i++)
		if (arr[i] != 1)
			arr[i] = 0;

	cout << "\nThe K-map is:\n\t\t";

	for (size_t i = 0; i < 8; i++)
	{
		if (i == 4)
			cout << "\n\t\t";
		cout << arr[i] << "\t";
	}
	cout << endl << endl;

	delete[] arr;
	arr = NULL;
}

void essential_primes(vector<string> primes, vector<vector<string>> res_primes, vector<string> min_terms)
{
	vector<string> zero, one, two, three, four, five, six, seven;
	vector<string> essentials;
	for (size_t i = 0; i < res_primes.size(); i++)
	{
		for (size_t j = 0; j < res_primes[i].size(); j++)
		{
			if (res_primes[i][j] == "0")
				zero.push_back(primes[i]);
			if (res_primes[i][j] == "1")
				one.push_back(primes[i]);
			if (res_primes[i][j] == "2")
				two.push_back(primes[i]);
			if (res_primes[i][j] == "3")
				three.push_back(primes[i]);
			if (res_primes[i][j] == "4")
				four.push_back(primes[i]);
			if (res_primes[i][j] == "5")
				five.push_back(primes[i]);
			if (res_primes[i][j] == "6")
				six.push_back(primes[i]);
			if (res_primes[i][j] == "7")
				seven.push_back(primes[i]);
		}
	}

	//remove the dublicates in each vector of the seven
	{
	for (size_t i = 0; i < zero.size(); i++)
		for (int j = i + 1; j < zero.size(); j++)
			if (zero[i] == zero[j])
			{
				zero.erase(zero.begin() + j);
				j--;
			}
	for (size_t i = 0; i < one.size(); i++)
		for (int j = i + 1; j < one.size(); j++)
			if (one[i] == one[j])
			{
				one.erase(one.begin() + j);
				j--;
			}
	for (size_t i = 0; i < two.size(); i++)
		for (int j = i + 1; j < two.size(); j++)
			if (two[i] == two[j])
			{
				two.erase(two.begin() + j);
				j--;
			}
	for (size_t i = 0; i < three.size(); i++)
		for (int j = i + 1; j < three.size(); j++)
			if (three[i] == three[j])
			{
				three.erase(three.begin() + j);
				j--;
			}
	for (size_t i = 0; i < four.size(); i++)
		for (int j = i + 1; j < four.size(); j++)
			if (four[i] == four[j])
			{
				four.erase(four.begin() + j);
				j--;
			}
	for (size_t i = 0; i < five.size(); i++)
		for (int j = i + 1; j < five.size(); j++)
			if (five[i] == five[j])
			{
				five.erase(five.begin() + j);
				j--;
			}
	for (size_t i = 0; i < six.size(); i++)
		for (int j = i + 1; j < six.size(); j++)
			if (six[i] == six[j])
			{
				six.erase(six.begin() + j);
				j--;
			}
	for (size_t i = 0; i < seven.size(); i++)
		for (int j = i + 1; j < seven.size(); j++)
			if (seven[i] == seven[j])
			{
				seven.erase(seven.begin() + j);
				j--;
			}
	}
	
	if (zero.size() == 1)
		essentials.push_back(zero[0]);
	if (one.size() == 1)
		essentials.push_back(one[0]);
	if (two.size() == 1)
		essentials.push_back(two[0]);
	if (three.size() == 1)
		essentials.push_back(three[0]);
	if (four.size() == 1)
		essentials.push_back(four[0]);
	if (five.size() == 1)
		essentials.push_back(five[0]);
	if (six.size() == 1)
		essentials.push_back(six[0]);
	if (seven.size() == 1)
		essentials.push_back(seven[0]); 
	
	
	for (size_t i = 0; i < essentials.size(); i++) //removing the duplicates in essentials
	{
		for (int j = i + 1; j < essentials.size(); j++)
			if (essentials[i] == essentials[j])
			{
				essentials.erase(essentials.begin() + j);
				j--;
			}
	}

	int rep0 = 0, rep1 = 0;    //turning binary to literals 
	for (size_t i = 0; i < essentials.size(); i++)
	{
		if (essentials[i][0] == '0')
		{
			essentials[i].replace(0, 1, "A' ");
			rep0 = 3;
		}
		if (essentials[i][0] == '1')
		{
			essentials[i].replace(0, 1, "A ");
			rep0 = 2;
		}

		if (rep0 == 3)
		{
			if (essentials[i][3] == '0')
			{
				essentials[i].replace(3, 1, "B' ");
				rep1 = 6;
			}
			if (essentials[i][3] == '1')
			{
				essentials[i].replace(3, 1, "B ");
				rep1 = 5;
			}
		}	
		if (rep0 == 2)
		{
			if (essentials[i][2] == '0')
			{
				essentials[i].replace(2, 1, "B' ");
				rep1 = 5;
			}
			if (essentials[i][2] == '0')
			{
				essentials[i].replace(2, 1, "B ");
				rep1 = 4;
			}
		}
		if (rep0 == 0)
		{
			if (essentials[i][1] == '0')
			{
				essentials[i].replace(1, 1, "B' ");
				rep1 = 4;
			}
			if (essentials[i][1] == '0')
			{
				essentials[i].replace(1, 1, "B ");
				rep1 = 3;
			}
		}

		if (rep1 == 6)
		{
			if (essentials[i][6] == '0')
				essentials[i].replace(6, 1, "C' ");
			if (essentials[i][6] == '1')
				essentials[i].replace(6, 1, "C ");
		}
		if (rep1 == 5)
		{
			if (essentials[i][5] == '0')
				essentials[i].replace(5, 1, "C' ");
			if (essentials[i][5] == '1')
				essentials[i].replace(5, 1, "C ");
		}
		if (rep1 == 4)
		{
			if (essentials[i][4] == '0')
				essentials[i].replace(4, 1, "C' ");
			if (essentials[i][4] == '1')
				essentials[i].replace(4, 1, "C ");
		}
		if (rep1 == 3)
		{
			if (essentials[i][3] == '0')
				essentials[i].replace(3, 1, "C' ");
			if (essentials[i][3] == '1')
				essentials[i].replace(3, 1, "C ");
		}
		
		if (rep1 == 0 && rep0 == 3)
		{
			if (essentials[i][4] == '0')
				essentials[i].replace(4, 1, "C' ");
			if (essentials[i][4] == '1')
				essentials[i].replace(4, 1, "C ");
		}
		if (rep1 == 0 && rep0 == 2)
		{
			if (essentials[i][3] == '0')
				essentials[i].replace(3, 1, "C' ");
			if (essentials[i][3] == '1')
				essentials[i].replace(3, 1, "C ");
		}
		if (rep1 == 0 && rep0 == 0)
		{
			if (essentials[i][2] == '0')
				essentials[i].replace(2, 1, "C' ");
			if (essentials[i][2] == '1')
				essentials[i].replace(2, 1, "C ");
		}

		rep0 = 0; rep1 = 0;
	}
	//B
	for (size_t i = 0; i < essentials.size(); i++)
	{
		for (size_t j = 0; j < essentials[i].size(); j++)
		{
			if (essentials[i][j] == '1')
			{
				essentials[i].replace(j, 1, "B ");
				j--;
			}
		}
	}

	for (size_t i = 0; i < essentials.size(); i++)
	{
		for (size_t j = 0; j < essentials[i].size(); j++)
		{
			if (essentials[i][j] == '-')
			{
				essentials[i].erase(essentials[i].begin() + j);
				j--;
			}
		}
	}

	cout << endl << "\tF = \"" << essentials[0];
	for (size_t i = 1; i < essentials.size(); i++)
	{
		cout << "  +  " << essentials[i];
	}
	cout << "\"\n";
}

void Bool_Function(vector<string> bin_min_terms, vector<int> int_min_terms, int size)
{
	vector<string> min_terms(int_min_terms.size());
	for (size_t i = 0; i < int_min_terms.size(); i++)
	{
		min_terms[i] = to_string(int_min_terms[i]);
	}
	int counter = 0, in0A = 0, in1A = 0, in2A = 0, in3A = 0;
	vector<string> zeros, ones, twos, threes;
	vector<string> res_zeros, res_ones, res_twos, res_threes;
	for (size_t i = 0; i < size; i++)    //first table
	{
		if (bin_min_terms[i] == "000")
		{
			zeros.push_back(bin_min_terms[i]); in0A = 1;
			res_zeros.push_back("0");
		}
		else if (bin_min_terms[i] == "111")
		{
			threes.push_back(bin_min_terms[i]); in3A = 1;
			res_threes.push_back("7");
		}
		else
		{
			counter = 0;
			for (size_t j = 0; j < 3; j++)
				if (bin_min_terms[i][j] == '1')
					counter++;

			if (counter == 1)
			{
				ones.push_back(bin_min_terms[i]); in1A++;
				res_ones.push_back(min_terms[i]);
			}
			if (counter == 2)
			{
				twos.push_back(bin_min_terms[i]); in2A++;
				res_twos.push_back(min_terms[i]);
			}
		}
	}

	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function
	// kaml 7efz el minterms 3shan tb2a tb3tha ll implicant_primes function

	vector<string> ticked, res_ticked, zerosB, onesB, twosB;
	vector<vector<string>> res_zerosB, res_onesB, res_twosB;
	int in0B = 0, in1B = 0, in2B = 0;
	//2nd table
	string x;
	if (in0A > 0 && in1A > 0)
	{
		ticked.push_back(zeros[0]);
	//	res_ticked.resize(in1A + 1);
		res_ticked.push_back("0");
		in0B = in1A;
		res_zerosB.resize(in1A);
		for (size_t i = 0; i < in1A; i++)
		{
			ticked.push_back(ones[i]);
			res_ticked.push_back(res_ones[i]);
			x = zeros[0];
			x.replace(ones[i].find('1'), 1, "-");
			zerosB.push_back(x);
			res_zerosB[i].push_back("0");
			res_zerosB[i].push_back(res_ones[i]);
		}
	}
	counter = 0;
	int index = 0;
	if (in1A > 0 && in2A > 0)
	{
		for (size_t i = 0; i < in1A; i++)
		{
			for (size_t j = 0; j < in2A; j++)
			{
				for (size_t k = 0; k < 3; k++)
					if (ones[i][k] != twos[j][k])
					{
						counter++; index = k;
					}
				if (counter == 1)
				{
					in1B++;
					ticked.push_back(ones[i]); ticked.push_back(twos[j]);
					res_ticked.push_back(res_ones[i]); res_ticked.push_back(res_twos[j]);
					x = ones[i];
					x.replace(index, 1, "-");
					onesB.push_back(x);
					res_onesB.push_back({ res_ones[i], res_twos[j] });
				}
				counter = 0;
			}
		}
	}
	if (in2A > 0 && in3A > 0)
	{
		ticked.push_back(threes[0]);
		res_ticked.push_back("7");
		in2B = in2A;
		for (size_t i = 0; i < in2A; i++)
		{
			ticked.push_back(twos[i]);
			res_ticked.push_back(res_twos[i]);
			x = threes[0];
			x.replace(twos[i].find('0'), 1, "-");
			twosB.push_back(x);
			res_twosB.push_back({ "7", res_twos[i] });
		}
	}


	//after finishing table B
	//the possiblities are (no table B*, zeros*, ones*, twos*, zeros&twos*----------->no constructing table C, 
	//                      zeros&ones, ones&twos, zeros&ones&twos----------->constructs table C) 
	if (in0B == 0 && in1B == 0 && in2B == 0)  //no table B
	{
		vector<string> primes(bin_min_terms);
		vector<vector<string>> res_primes;
		for (size_t i = 0; i < min_terms.size(); i++)
		{
			res_primes.push_back({ min_terms[i] });
		}
		essential_primes(primes, res_primes, min_terms);
		cout << endl;
		return;
	}
	
	for (size_t i = 0; i < ticked.size(); i++) //removing the duplicates in ticked
	{
		for (int j = i + 1; j < ticked.size(); j++)
		{
			if (ticked[i] == ticked[j])
			{
				ticked.erase(ticked.begin() + j);
				res_ticked.erase(res_ticked.begin() + j); 
				j--;
			}
		}
	}

	// this if takes care of the case (ones)
	if (in0B == 0 && in2B == 0)  //han7ot in1B m3 elly m4 ticked mn table A "becasue there will be no table C"
	{
		vector<string>primes; bool exist = false;
		vector<vector<string>> res_primes;
		for (size_t i = 0; i < bin_min_terms.size(); i++)
		{
			for (size_t j = 0; j < ticked.size(); j++)
			{
				if (bin_min_terms[i] == ticked[j])
					exist = true;
			}
			if (exist == false)
			{
				primes.push_back(bin_min_terms[i]); res_primes.push_back({ min_terms[i] });
			}
			exist = false;
		}
		for (size_t i = 0; i < onesB.size(); i++)
		{
			primes.push_back(onesB[i]);
			res_primes.push_back(res_onesB[i]);
		}
		//keda prime is full
		//ektb code prime implicant table w cout el function: prime(primes, res_primes); return;
		//return;
		essential_primes(primes, res_primes, min_terms);
		return;
	}

	// this if takes care of the cases (zeros&twos, zeros, twos)
	if (in1B == 0)  //han7ot in0B w in in2B m3 elly m4 ticked mn table A "becasue there will be no table C"
	{
		vector<string>primes; bool exist = false;
		vector<vector<string>> res_primes;
		for (size_t i = 0; i < bin_min_terms.size(); i++)
		{
			for (size_t j = 0; j < ticked.size(); j++)
			{
				if (bin_min_terms[i] == ticked[j])
					exist = true;
			}
			if (exist == false)
			{
				primes.push_back(bin_min_terms[i]); res_primes.push_back({ min_terms[i] });
			}
			exist = false;
		}
		for (size_t i = 0; i < zerosB.size(); i++)
		{
			primes.push_back(zerosB[i]);
			res_primes.push_back(res_zerosB[i]);
		}
		for (size_t i = 0; i < twosB.size(); i++)
		{
			primes.push_back(twosB[i]);
			res_primes.push_back(res_twosB[i]);
		}     //keda prime is full
		//ektb code prime implicant table w cout el function: prime(primes, res_primes); return;
		//return;
		essential_primes(primes, res_primes, min_terms);
		return;
	}

	//3rd table (cases: (zeros&ones), (ones&twos), (zeros&ones&twos))
	vector<string> tickedB, zerosC, onesC;  //ticked has no dashes; tickedB has 1 dashes
	vector<vector<string>> res_tickedB; //this vector of vector is of two columns
	vector<vector<string>> res_zerosC, res_onesC; //this vector of vector is of four columns
	int in0C = 0, in1C = 0;
	int vec_index = -1;
	if (in0B > 0 && in1B > 0)  //case of zeros&ones
	{
		for (size_t i = 0; i < in0B; i++)
		{
			for (size_t j = 0; j < in1B; j++)
			{
				for (size_t k = 0; k < 3; k++)
					if (zerosB[i][k] != onesB[j][k])
					{
						counter++; index = k;
					}
				if (counter == 1)
				{
					vec_index++;
					in0C++;
					tickedB.push_back(zerosB[i]); tickedB.push_back(onesB[j]);
					res_tickedB.push_back(res_zerosB[i]); res_tickedB.push_back(res_onesB[j]);
					x = zerosB[i];
					x.replace(index, 1, "-");
					zerosC.push_back(x);
					res_zerosC.push_back({ res_zerosB[i] });
					for (size_t w = 0; w < res_onesB[j].size(); w++)
						res_zerosC[vec_index].push_back({ res_onesB[j][w] });
				}
				counter = 0;
			}
		}
	}
	vec_index = -1;
	if (in1B > 0 && in2B > 0) //case of ones&twos
	{
		for (size_t i = 0; i < in1B; i++)
		{
			for (size_t j = 0; j < in2B; j++)
			{
				for (size_t k = 0; k < 3; k++)
					if (onesB[i][k] != twosB[j][k])
					{
						counter++; index = k;
					}
				if (counter == 1)
				{
					vec_index++;
					in1C++;
					tickedB.push_back(onesB[i]); tickedB.push_back(twosB[j]);
					res_tickedB.push_back(res_onesB[i]); res_tickedB.push_back(res_twosB[j]);
					x = onesB[i];
					x.replace(index, 1, "-");
					onesC.push_back(x);
					res_onesC.push_back({ res_onesB[i] });
					for (size_t w = 0; w < res_twosB[j].size(); w++)
						res_onesC[vec_index].push_back({ res_twosB[j][w] });
				}
				counter = 0;
			}
		}
	}

	//after finishing table C we have three cases:            
	//(no table C),(zeros),(ones),(zeros&ones)			   
														   
	if (in0C == 0 && in1C == 0)  //no table C
	//han7ot elly fe table B m3 elly m4 ticked mn table A
	{													   
		vector<string>primes; bool exist = false;  
		vector<vector<string>>res_primes;
		for (size_t i = 0; i < bin_min_terms.size(); i++)  
		{												   
			for (size_t j = 0; j < ticked.size(); j++)	   
			{											   
				if (bin_min_terms[i] == ticked[j])		   
					exist = true;						   
			}											   
			if (exist == false)
			{
				primes.push_back(bin_min_terms[i]);
				res_primes.push_back({ min_terms[i] });
			}
			exist = false;
		}												   
		for (size_t i = 0; i < zerosB.size(); i++)		   
		{												   
			primes.push_back(zerosB[i]);
			res_primes.push_back(res_zerosB[i]);
		}												   
		for (size_t i = 0; i < twosB.size(); i++)		   
		{												   
			primes.push_back(twosB[i]);	
			res_primes.push_back(res_twosB[i]);
		} 												   
		for (size_t i = 0; i < onesB.size(); i++)		   
		{												   
			primes.push_back(onesB[i]);
			res_primes.push_back(res_onesB[i]);
		}//keda prime is full							   
		//ektb code prime implicant table w cout el function: prime(primes, res_primes); return;
		//return;
		essential_primes(primes, res_primes, min_terms);
		return;
	}

	for (size_t i = 0; i < tickedB.size(); i++) //removing the duplicates in tickedB
	{
		for (int j = i + 1; j < tickedB.size(); j++)
		{
			if (tickedB[i] == tickedB[j])
			{
				tickedB.erase(tickedB.begin() + j);
				res_tickedB.erase(res_tickedB.begin() + j);
				j--;
			}
		}
	}
	//lw fy table C ahn7ot elly fyh + elly m4 mwgod fe ticked aw tickedB
	vector<string>primes; bool exist = false;
	vector<vector<string>>res_primes;
	for (size_t i = 0; i < bin_min_terms.size(); i++)
	{
		for (size_t j = 0; j < ticked.size(); j++)
		{
			if (bin_min_terms[i] == ticked[j])
				exist = true;
		}
		if (exist == false)
		{
			primes.push_back(bin_min_terms[i]);
			res_primes.push_back({ min_terms[i] });
		}
		exist = false;
	}

	for (size_t i = 0; i < zerosB.size(); i++)
	{
		for (size_t j = 0; j < tickedB.size(); j++)
		{
			if (zerosB[i] == tickedB[j])
				exist = true;
		}
		if (exist == false)
		{
			primes.push_back(zerosB[i]);
			res_primes.push_back(res_zerosB[i]);
		}
		exist = false;
	}
	for (size_t i = 0; i < onesB.size(); i++)
	{
		for (size_t j = 0; j < tickedB.size(); j++)
		{
			if (onesB[i] == tickedB[j])
				exist = true;
		}
		if (exist == false)
		{
			primes.push_back(onesB[i]);
			res_primes.push_back(res_onesB[i]);
		}
		exist = false;
	}
	for (size_t i = 0; i < twosB.size(); i++)
	{
		for (size_t j = 0; j < tickedB.size(); j++)
		{
			if (twosB[i] == tickedB[j])
				exist = true;
		}
		if (exist == false)
		{
			primes.push_back(twosB[i]);
			res_primes.push_back(res_twosB[i]);
		}
		exist = false;
	}

	for (size_t i = 0; i < zerosC.size(); i++)
	{
		primes.push_back(zerosC[i]);
		res_primes.push_back(res_zerosC[i]);
	}
	for (size_t i = 0; i < onesC.size(); i++)
	{
		primes.push_back(onesC[i]);
		res_primes.push_back(res_onesC[i]);
	}
	//keda prime is full
		//ektb code prime implicant table w cout el function: prime(primes, res_primes); return;
		//return;
	essential_primes(primes, res_primes, min_terms);
	return;

}



void main()
{
	string order[8] = { "First","Second","Third","Fourth",         //just for guiding the user
		                "Fifth","Sixth","Seventh","Eighth" };  
	
	int size;
	cout << "Please Enter The Number of Min Terms in Your Function: ";
	cin >> size;
	while (size > 8 || size < 0)                      // validating the size of the minterms
	{
		cout << "\nThis program deals with Three-Variable K-Maps, so please enter a number between 0 and 8: ";
		cin >> size;
	}

	vector<int> min_terms(size);
	
	//if size==0
	// draw the k_map empty and print "f=0", and return()
	if (size == 0)
	{
		cout << "\nThe K-map is:\n\t\t";

		for (size_t i = 0; i < 8; i++)
		{
			if (i == 4)
				cout << "\n\t\t";
			cout << "0\t";
		}
		cout << endl << "\tF = 0\n";
		return;
	}
	//if size==8
	// draw the k_map full with 1s and print "f=1", and return()
	if (size == 8)
	{
		cout << "\nThe K-map is:\n\t\t";

		for (size_t i = 0; i < 8; i++)
		{
			if (i == 4)
				cout << "\n\t\t";
			cout << "1\t";
		}
		cout << endl << "\tF = 1\n";
		return;
	}
	
	cout << "\nPlease Enter The Min Terms of Your Function as Decimal Numbers in Ascending Order\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter the " << order[i] << " decimal: ";
		cin >> min_terms[i];
		while (min_terms[i] > 7 || min_terms[i] < 0)        // validating the minterms
		{
			cout << "This program deals with Three-Variable K-Maps, so please enter a minterm between 0 and 7: ";
			cin >> min_terms[i];
		}
	}

	//sorting in ascending order: (don't do to put in the documentation as limits)
	//for (size_t i = 0; i < size; i++)
	//{
	//	for (size_t j = 0; j < size; j++)
	//	{
	//
	//	}
	//}

	//checking for dublicates and erasing them: *(only works if the min_terms are sorted ascendingly)
	Erasing_duplicates(min_terms);
	size = min_terms.size();
	
	//2) generating the k-map
	Printing_kmap(min_terms, size);
	//Ýí ÛáØÉ ÌÇãÏÉ åäÇ
	//el mafrod el k map tb2a :   0   1   3   2
	                  //          4   5   7   6
	//ÎáÇÕ ÕáÍÊåÇ

	//3) turning the decimals to binaries and storing them in strings
	//(could have wrote a code to do it but the cases are limited and would increase complexity with no need to do so)
	vector<string> bin_min_terms(size);
	for (size_t i = 0; i < size; i++)
	{
		switch (min_terms[i])
		{
		case 0:
			bin_min_terms[i] = "000"; break;
		case 1:						  
			bin_min_terms[i] = "001"; break;
		case 2:						  
			bin_min_terms[i] = "010"; break;
		case 3:						  
			bin_min_terms[i] = "011"; break;
		case 4:						  
			bin_min_terms[i] = "100"; break;
		case 5:						  
			bin_min_terms[i] = "101"; break;
		case 6:						  
			bin_min_terms[i] = "110"; break;
		case 7:						  
			bin_min_terms[i] = "111"; break;
		}
	}

	//3) Quine McCulsky
	Bool_Function(bin_min_terms, min_terms, size);

}