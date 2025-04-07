
# ✅ Team Git Workflow Guide

## 📌 Purpose
This guide describes the standard Git workflow for team members using feature branches and pushing updates to the `main` branch.

---

## 🔁 Step-by-Step Git Workflow

### 🔹 1. Create or switch to your personal branch
```bash
git checkout -b develop_YourName   # Create a new branch
# OR
git checkout develop_YourName      # Switch to your existing branch
```

---

### 🔹 2. Make your changes locally
Edit files as needed. Check what's changed:
```bash
git status
```

---

### 🔹 3. Stage and commit your changes
```bash
git add .                           # Or specify individual files
git commit -m "Describe your update"
```

---

### 🔹 4. Push your branch to GitHub
If first time pushing this branch:
```bash
git push -u origin develop_YourName
```

After that:
```bash
git push
```

---

### 🔹 5. Merge your work into `main` when ready

#### a. Switch to `main` branch
```bash
git checkout main
```

#### b. Pull latest updates from remote
```bash
git pull origin main
```

#### c. Merge your feature branch into main
```bash
git merge develop_YourName
```

---

### 🔹 6. Push the updated `main` to GitHub
```bash
git push origin main
```

---

### 🔹 7. (Optional) Clean up your branch
If no longer needed:
```bash
git branch -d develop_YourName
git push origin --delete develop_YourName
```

---

## ⚔️ How to Solve Merge Conflicts

If you see something like this during merge:
```
CONFLICT (content): Merge conflict in somefile.c
Automatic merge failed; fix conflicts and then commit the result.
```

### 🧹 Step-by-step:

1. Open the file and look for conflict markers:
   ```
   <<<<<<< HEAD
   code from main
   =======
   code from develop_YourName
   >>>>>>> develop_YourName
   ```

2. Manually edit and keep the correct version.

3. After editing:
```bash
git add somefile.c
```

4. Then commit the merge:
```bash
git commit
```

5. Finally, push the resolved version:
```bash
git push origin main
```

---

## ✅ Tips
- Always pull before starting new work.
- Use clear, short commit messages.
- Coordinate merges to avoid conflicts.
