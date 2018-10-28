#define gc getchar_unlocked
#define pc putchar_unlocked

inline void Cin(int &num) {
	num = 0;
	char c = gc();
	int flag = 0;

	while(!((c >= '0' & c <= '9') || c == '-')) {
		c = gc();
	}

	if(c == '-') {
		flag = 1;
		c = gc();
	}

	while(c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + c - '0';
		c = gc();
	}

	if(flag == 1) {
		num = 0 - num;
	}
}

inline void Cout(int n) {
	int NN = n, rev, count = 0;
	rev = NN;

	if(NN == 0) {
		pc('0');
		pc('\n');
		return ;
	}

	while((rev % 10) == 0) {
		count++;
		rev /= 10;
	}

	rev = 0;

	while(NN != 0) {
		rev = (rev << 3) + (rev << 1) + NN % 10; 
		NN /= 10;
	}

	while(rev != 0) {
		pc(rev % 10 + '0');
		rev /= 10;
	}

	while(count--) {
		pc('0');
	}
}
