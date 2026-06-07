class Robot{
private:
    int width, height;
    int perimeter;
    int pos;
    bool moved;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        perimeter = 2 * (width + height) - 4;
        pos = 0;
        moved = false;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }

    vector<int> getPos() {
        if (pos < width) {
            return {pos, 0};
        }

        if (pos < width + height - 1) {
            return {width - 1, pos - width + 1};
        }

        if (pos < 2 * width + height - 2) {
            return {2 * width + height - pos - 3, height - 1};
        }

        return {0, perimeter - pos};
    }

    string getDir() {
        if (pos == 0) {
            return moved ? "South" : "East";
        }

        if (pos < width) {
            return "East";
        }

        if (pos < width + height - 1) {
            return "North";
        }

        if (pos < 2 * width + height - 2) {
            return "West";
        }

        return "South";
    }
};