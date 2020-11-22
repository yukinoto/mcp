#include <stdlib.h>

namespace mlib{
	//random in [l,r)
	int random(int l,int r)
	{
		if(l>=r)
			return -1;
		return ((rand()<<16)|rand())%(r-l)+l;
	}
}
