class Solution {
public:
    string predictPartyVictory(string senate) 
    {
      int n = senate.size();
      queue<int> qr, qd;
      for (int i = 0; i < n; i++)
      {
        if (senate[i] == 'R') qr.push(i);
        else qd.push(i);
      }
      while (qd.size() > 0 and qr.size() > 0)
      {
        int qd_id = qd.front(), qr_id = qr.front();
        qr.pop();
        qd.pop();
        if (qd_id < qr_id)
        {
          qd.push(qd_id+n);
        }
        else
        {
          qr.push(qr_id+n);
        }
      }
      cout << qr.size() << " " << qd.size();
      if (qr.size() > qd.size()) return "Radiant";
      else return "Dire";
      return "";
      
    }
      
};