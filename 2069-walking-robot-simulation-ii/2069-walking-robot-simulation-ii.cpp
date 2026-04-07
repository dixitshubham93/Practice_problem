class Robot {
public:
    vector<pair<int,int>> path;
    int idx = 0;
    int n;
    int width;
    int height;
    bool istime = true;
    Robot(int width, int height) {

        this->width = width;
        this->height = height;

        for(int i = 0; i < width; i++) {
            path.push_back({i, 0});
        }

      
        for(int i = 1; i < height; i++) {
            path.push_back({width - 1, i});
        }

       
        for(int i = width - 2; i >= 0; i--) {
            path.push_back({i, height - 1});
        }

       
        for(int i = height - 2; i > 0; i--) {
            path.push_back({0, i});
        }

        n = path.size();
    }

    void step(int num) {
        idx = (idx + num) % n;
        istime = false;
    }

    vector<int> getPos() {
        return {path[idx].first, path[idx].second};
    }

    string getDir(){

        if(idx < n) {        
            int x = path[idx].first;
            int y = path[idx].second;
            if(x==0&&y==0&&!istime){return "South";}
            if(y == 0) return "East";
            if(x ==width-1&&y>0) return "North";
            if(y== height-1&&x<width-1) return "West";
            if(x==0&&y>0){return "South";}
        }
        return "East";
    }
};