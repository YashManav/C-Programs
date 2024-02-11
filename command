//to create empty git repo
git init
//to add all file
git add .
//to commit change
git commit -am "message"
//to add repo url
git remote add origin https://github.com/YashManav/C-Programs.git
//add branch
git branch -M main
//finally push file
git push -u origin main
//tip of current branch is behind
git push -f origin main
