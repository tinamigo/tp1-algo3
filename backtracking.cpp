#include <vector>
#include <iostream>
#include <algorithm>
#include "auxs.cpp"

using namespace std;

int maxBeneficio_BT(int i, int w, const vector< pair <int,int> > &S, int maxPosible);

int maxBeneficio_BT(int i, int w, const vector< pair <int,int> > &S, int maxPosible){
	if (i==S.size()) return 0;
	maxPosible -= ben(S[i]);
	if (w - tam(S[i]) < 0) return maxBeneficio_BT(i+1, w, S, maxPosible);
	if (ben(S[i]) > maxPosible) return maxBeneficio_BT(i+1, w - tam(S[i]), S, maxPosible) + ben(S[i]);
	return max(maxBeneficio_BT(i+1, w - tam(S[i]), S, maxPosible) + ben(S[i]), maxBeneficio_BT(i+1, w, S, maxPosible));
}
