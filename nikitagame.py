arr1 = []

def recursion(start, end) :
        if(start == end):
                return 0;
        sumarr = 0;
        sumi = 0;
        count = 0;
        sumarr = sum(arr1[start:end]);
	if (sumarr % 2 == 1):
		return 0;
        for i in range(start,end):
                sumi = sumi + arr1[i];
		if (sumarr == 0 and sumi == 0):
			return end-1;
                if (sumi == sumarr/2):
                        return max(recursion(start,i+1),recursion(i+1,end))+1
        return count;

tests = int(raw_input());
for i in range(tests):
        n = int(raw_input());
        arr1 = map(int, raw_input().split());
        #for j in arr:
        #        arr1.append(int(j));
        res = recursion(0, n);
        print res
        arr1 = []
