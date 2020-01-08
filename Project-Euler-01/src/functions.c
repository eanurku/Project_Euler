
int GCD(int big,int small){
	if(big<small)
		GCD(small,big);
	if(small==0)
		return big;
	return(GCD(small,big%small));
}

int sumOfAP(int firstTerm, int commondiff, int noOfTerms){

	return ((2*firstTerm+commondiff*(noOfTerms-1))*noOfTerms)/2;
}
