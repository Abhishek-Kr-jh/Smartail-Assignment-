#include<bits/stdc++.h>
#define X real()
#define Y imag()

using namespace std;


// for tesing purpose;


// vector<complex<double>>generate_random_points()
// {
//     vector<complex<double>> points;
//     points.push_back({111,11});
//     points.push_back({6,6});
//     points.push_back({60,10});
//     points.push_back({30,13});
//     points.push_back({33,13}); 
//     return points;
// }

// generating 100 random cordinates;

vector<complex<double>>generate_random_points()
{
    vector<complex<double>> points;
    srand(time(0));
    for(int i = 0; i < 100; i++)
    {
       
        double a = rand()%100;
        double b = rand()%100;
        points.push_back({a,b});
    }
    return points;
 }
void print_points(vector<complex<double>> points) // for printing points;
{
    for(complex<double> x: points)
    {
        cout<<x<<" ";
    }
}
// stl functor (function object helping in sorting array of cordinate based on x cordinate)

class sortfun
{
    public:
    bool operator ()(complex<double> p, complex<double> q)
    {
        return p.X < q.X;
    }
};

/*
function calculating minimum distance among 3 or less than 3  points
*/
pair<double, pair<complex<double>, complex<double>>> calc(vector<complex<double>> points, int left, int right)
{
    double m = INT_MAX;
    pair<complex<double>, complex<double>> pts;
    for(int i = left; i <= right; i++)
    {
        for(int j = i+1; j <= right; j++)
        {
            if(m > abs(points[i]- points[j]))
            {
                pts = {points[i], points[j]};
                m = abs(points[i]- points[j]);
            }

        }

    }
    //cout<<pts.first<<" okll "<<pts.second;
    return {m, pts};

}
/*
    function recursively calculating distance two points; 
*/
pair<double, pair<complex<double>, complex<double>>> closest_pair(vector<complex<double>> points, int left, int right)
{
    int mid = left + (right- left)/2;
    if((right-left + 1) > 3)
    {
        /*
        if more than 3 points in array this recursively two call will be made using 
        one from 0 till mid(size/2) and other from mid+1 to end; 
        */
        pair<double, pair<complex<double>, complex<double>>> p = closest_pair(points, left, mid);
        pair<double, pair<complex<double>, complex<double>>> q = closest_pair(points, mid+1, right);
        // pair<complex<double>, complex<double>>pts;
        // double dis, tmp;
        vector<complex<double>>vec;
        vec.push_back(p.second.first);
        vec.push_back(p.second.second);
        vec.push_back(q.second.first);
        vec.push_back(q.second.second);
        

        double m = INT_MAX;
        pair<complex<double>, complex<double>> pts;
        for(int i = left; i <= 3; i++)
        {
            for(int j = i+1; j <= 3; j++)
            {
                if(m > abs(points[i]- points[j]))
                {
                    pts = {vec[i], vec[j]};
                    m = abs(vec[i]- vec[j]);
                }

            }

        }
        
        return {m,pts};

    }
    else
    {
        return calc(points, left, right); // if only 3 or less then 3 points in array (vector)then this will be called;
    }
    
    
}
int main()   // main function
{
    pair<double, pair<complex<double>, complex<double>>> pair_points;
    vector<complex<double>> points = generate_random_points(); // generating 100 random 2D points and storing in vector;
    
    // print_points(points);
    sort(points.begin(), points.end(),sortfun()); // sorting points with respect to x (x-axix point)value;
    print_points(points); //for printing points
    cout<<endl;
    pair_points = closest_pair(points,0, points.size()-1); // calculating shortest distance between two points
    cout<<"closest points are: "<<pair_points.second.first<<" and "<<pair_points.second.second<<", distance bw them are: "<<pair_points.first; // displaying distance;
    return 0;
}
