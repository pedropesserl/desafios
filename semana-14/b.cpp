#include <bits/stdc++.h>
using namespace std;

using pt = complex<double>;
#define px real()
#define py imag()

long cross(pt a, pt b) {
    return (conj(a) * b).py;
}

long twice_polygon_area(vector<pt>& ps) {
    long area = cross(ps[ps.size()-1], ps[0]);
    for (size_t i = 1; i < ps.size(); i++) {
        area += cross(ps[i-1], ps[i]);
    }
    return area;
} 

long int_coords_in_line(pt start, pt end) { // não inclui o ponto start
    long rise = abs(start.py - end.py);
    long run  = abs(start.px - end.px);
    if (rise == 0) { // linha horizontal
        return run;
    }
    if (run == 0) { // linha vertical
        return rise;
    }
    long maior = max(run, rise), menor = min(run, rise);
    if (maior % menor == 0) {
        return menor;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n;
    cin >> n;
    vector<pt> poly(n);
    for (long i = 0; i < n; i++) {
        long x, y;
        cin >> x >> y;
        poly[i] = pt(x, y);
    }

    // Teorema de Pick: A = i + b/2 - 1
    //              <=> i = A - b/2 + 1
    long twoA = twice_polygon_area(poly);
    long b = int_coords_in_line(poly[n - 1], poly[0]);
    for (long i = 0; i < n - 1; i++) {
        b += int_coords_in_line(poly[i], poly[i + 1]);
    }
    if (twoA % 2 == 1) {
        twoA++;
    }
    long i = twoA/2 - b/2 + 1;

    cout << i << " " << b << "\n";

    return 0;
}
