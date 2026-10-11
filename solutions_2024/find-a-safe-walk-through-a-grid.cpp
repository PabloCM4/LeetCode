    //  Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        //  Using 01 BFS

        int max_row = grid.size();
        int max_col = grid[0].size();

        //  Initialize the distance to every node to be infinite
        //  1d vector, so the nodes will have the position of ( (row*col) + (col) ).
        vector<int> dist( max_row*max_col, INT_MAX );

        deque<int> my_queue;

        dist[0] = grid[0][0];

        my_queue.push_front(0);

        while( !my_queue.empty() )
        {
            //  Read the node we are going to check and delete it from the queue
            int checking_node = my_queue.front();
            my_queue.pop_front();
            
            //  Check the lower neighbour (in case we are not in the lowest) 
            if ( (checking_node / max_col) < (max_row - 1) )
            {
                int neighbour = checking_node + max_col;
                int weight = grid[neighbour/max_col][neighbour%max_col];

                if(dist[neighbour] > dist[checking_node] + weight )
                {
                    dist[neighbour] = dist[checking_node] + weight;

                    // Push to the queue based on the weight (go first the lower cost path)
                    if (weight == 0)
                    {
                        my_queue.push_front(neighbour); // If weight is 0, push to front
                    }
                    else
                    {
                        my_queue.push_back(neighbour);  // If weight is 1, push to back
                    }
                }
            
            }

            //  Check the right neighbour (in case we are not at the most right)
            if ( (checking_node % max_col) < (max_col - 1) )
            {
                int neighbour = checking_node + 1;
                int weight = grid[neighbour/max_col][neighbour%max_col];

                if(dist[neighbour] > dist[checking_node] + weight )
                {
                    dist[neighbour] = dist[checking_node] + weight;

                    // Push to the queue based on the weight (go first the lower cost path)
                    if (weight == 0)
                    {
                        my_queue.push_front(neighbour); // If weight is 0, push to front
                    }
                    else
                    {
                        my_queue.push_back(neighbour);  // If weight is 1, push to back
                    }
                }
            
            }

            //  Check the upper neighbour (in case we are not at the uppermost)
            if ( (checking_node / max_col) > 0 )
            {
                int neighbour = checking_node - max_col;
                int weight = grid[neighbour/max_col][neighbour%max_col];

                if(dist[neighbour] > dist[checking_node] + weight )
                {
                    dist[neighbour] = dist[checking_node] + weight;

                    // Push to the queue based on the weight (go first the lower cost path)
                    if (weight == 0)
                    {
                        my_queue.push_front(neighbour); // If weight is 0, push to front
                    }
                    else
                    {
                        my_queue.push_back(neighbour);  // If weight is 1, push to back
                    }
                }
            
            }

            //  Check the left neighbour (in case we are not at the most left)
            if ( (checking_node % max_col) > 0 )
            {
                int neighbour = checking_node - 1;
                int weight = grid[neighbour/max_col][neighbour%max_col];

                if(dist[neighbour] > dist[checking_node] + weight )
                {
                    dist[neighbour] = dist[checking_node] + weight;

                    // Push to the queue based on the weight (go first the lower cost path)
                    if (weight == 0)
                    {
                        my_queue.push_front(neighbour); // If weight is 0, push to front
                    }
                    else
                    {
                        my_queue.push_back(neighbour);  // If weight is 1, push to back
                    }
                }
            
            }
            
        }   //  while( !my_queue.empty() )

        return (dist[ (max_row*max_col) - 1] < health);

        
    }
};