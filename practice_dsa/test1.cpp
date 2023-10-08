class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        string s;
        vector<unordered_map<char,int>> position_to_map(votes[0].size());

        // it will hold position to hasshet;


        for(int i =0;i<votes.size();i++){
            for(int j =0;j<votes[i].size();j++){
                position_to_map[j][votes[i][j]]++;
            }
        }

        for(int i=0;i<position_to_map.size();i++){
            cout<<i<<endl;
            unordered_map<char,int>::iterator it;
            for(it = position_to_map[i].begin();it!=position_to_map[i].end();it++){
                cout<<(*it).first<<" "<<(*it).second<<endl;
            }
        }

        cout<<endl<<endl;

        
        for(int i =0;i<position_to_map.size();i++){
            // perform every logic in this loop
            vector<char> maxes;
            int max = INT_MIN;
            unordered_map<char,int>::iterator it;
            for(it = position_to_map[i].begin();it!=position_to_map[i].end();it++){
                if((*it).second>max){
                    if(s.find((*it).first)== string::npos){
                        maxes.clear();
                    maxes.push_back((*it).first);
                    max = (*it).second;

                    }
                    
                }else if((*it).second==max){
                    if(s.find((*it).first)== string::npos)
                        maxes.push_back((*it).first);
                }
                
            }

            if(maxes.size()>1){
                int tie_break=0;
                int j =i+1;
                while(!tie_break && j<position_to_map.size()){
                    if(position_to_map[j][maxes[0]]>position_to_map[j][maxes[1]]){
                        tie_break=1;
                        s.push_back(maxes[0]);
                        s.push_back(maxes[1]);
                    }else if(position_to_map[j][maxes[0]]<position_to_map[j][maxes[1]]){
                        tie_break=1;
                        s.push_back(maxes[1]);
                        s.push_back(maxes[0]);

                    }
                  
                    j++;
                    
                }  
                if(tie_break==0){
                    cout<<i<<endl;
                    copy(maxes.begin(),maxes.end(),ostream_iterator<char>(cout," "));
                    sort(maxes.begin(),maxes.end());
                    s.push_back(maxes[0]);
                }              
            }else if(maxes.size()>0){
                s.push_back(maxes[0]);

            }


        }
        

      


        return s;

    }
};