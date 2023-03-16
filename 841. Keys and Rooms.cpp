class Solution {
public:
    void check_room(vector<vector<int>>& rooms, vector<bool>& unlockable, int i){
        unlockable[i] = true;

        if (rooms[i].size() == 0) return;
        
        else{
            for (int j = 0; j < rooms[i].size(); j++){
                if (! unlockable[rooms[i][j]]){
                check_room(rooms, unlockable, rooms[i][j]);
                }
                // continue;
            }
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> unlockable(rooms.size(), false);

        int count = 0;
        check_room(rooms, unlockable, 0);
    
        for (int i = 0; i < unlockable.size(); i++){
            if (unlockable[i] == true) count++;
        }

        if (count == unlockable.size()) return true;

        return false;
    }
};