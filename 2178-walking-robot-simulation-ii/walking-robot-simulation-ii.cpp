class Robot {
public:

   // 0=east, 1=north, 2=west, 3=south
   int i = 0;
   int j = 0;
   vector<vector<int>>pos;
   bool moved = false;
   int index = 0;
   int peri;
    
    Robot(int width, int height) {
        
        pos.push_back({0,0,3});
        for (int i = 1; i < width; i++){
            pos.push_back({i,0,0});
        }
        for (int i = 1; i < height; i++){
            pos.push_back({width-1,i,1});
        }
        for (int i = width-2; i>=0; i--){
            pos.push_back({i,height-1,2});
        }
        for (int i = height-2; i >= 0; i--){
            pos.push_back({0,i,3});
        }
        peri = 2*(width+height)-4;
    }
    
    void step(int num) {
        moved = true;
        index = (index+num)%peri;
        // while (num--){
        //     //east
        //     if (dir == "East"){
        //         if (j+1 < grid.size()){
        //             j++;
        //         }
        //         else{
        //             dir = "North";
        //             i++;
        //         }
        //     }
        //     //north
        //     else if (dir == "North"){
        //         if (i+1 < grid[0].size()){
        //             i++;
        //         }
        //         else{
        //             dir = "West";
        //             j--;
        //         }
        //     }
        //     //west
        //     else if (dir == "West"){
        //         if (j-1 >= 0){
        //             j--;
        //         }
        //         else{
        //             dir = "South";
        //             i--;
        //         }
        //     }
        //     //south
        //     else if (dir == "South"){
        //         if (i-1 >= 0){
        //             i--;
        //         }
        //         else{
        //             dir = "East";
        //             j++;
        //         }
        //     }
        //}
    }
    
    vector<int> getPos() {
        if (moved == false){
            return {0,0};
        }
        else {
            return {pos[index][0], pos[index][1]};
        }
    }
    
    string getDir() {
        if (moved == false){
            return "East";
        }
        if (pos[index][2] == 0) return "East";
        else if (pos[index][2] == 1) return "North";
        else if (pos[index][2] == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */