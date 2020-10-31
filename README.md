# Smartail-Assignment-




Algorithm 
1.	Input 100 points and store it in a vector 
2.	Sort all these points according to X-Coordinate
3.	Now use divide and concur method to solve the problem.
4.	 We divide the points in two parts from 0 to size/2 and size/2 +1 to size and recursively call the function until size of the array become three or less
5.	Apply brute force approach to calculate nearest point and distance between them on remaining three or less point.

Complexity: (N log N)



read points [] = generate random number    // read random 100 points;
N = size(points) // size of  
sort(points) // sort points based on x coordinate
call closest pair (points, 0, N-1)

procedure closest pair (points [], L, R)
    M = L + (R-L)/2
    if R - L + 1 > 3 then
        pair left = closest pair(points, L, M)
        pair right = closest pair(points, M + 1, R)
        store all 4 point in ARR // 2 from pair left and 2 from pair right
        calculate best among four and return
    else    // R - L + 1 <= 3 then
        calculate nearest point using brute force and return pair_of_point answer distance between them;
 

Note* Complete code is in the cpp file.
