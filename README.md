# Hacktoberfest2019
Happy Hacktober! This is a beginner friendly repository made specifically for Hacktoberfest that helps you get your first PR.

# Hacktoberfest

# Instructions :
### 1. Register yourself for Hacktoberfest
###### Link to register: https://hacktoberfest.digitalocean.com/

![register](https://user-images.githubusercontent.com/42115530/65821155-7f724600-e24f-11e9-90ed-8a956b0a854a.JPG)

### 2. Getting Started
#### See Our Website at: https://hacktoberfest.netlify.com/

![website](https://user-images.githubusercontent.com/42115530/65821073-6f0d9b80-e24e-11e9-883e-262588bdef7f.JPG)

#### Move to Instructions by clicking on the <pre>START CONTRIBUTING</pre> button 

![start](https://user-images.githubusercontent.com/42115530/65821081-7fbe1180-e24e-11e9-8e98-756ce51d6431.JPG)

#### Read the Instructions and click Done at the end to move to the repository.

![instructions](https://user-images.githubusercontent.com/42115530/65821120-0a067580-e24f-11e9-8f06-bd231a6ab96d.JPG)

![instructions 2](https://user-images.githubusercontent.com/42115530/65821196-ec85db80-e24f-11e9-8178-7ebbed1abd73.JPG)

### 3. Star and Fork this Repository
###### You can star and fork this repository on GitHub by navigating at the top of this repository.

![fork](https://user-images.githubusercontent.com/42115530/65821168-aaf53080-e24f-11e9-8046-61bdf586d969.jpeg)

![star](https://user-images.githubusercontent.com/42115530/65821169-ad578a80-e24f-11e9-90f6-37abbf9e8489.jpeg)

###### GitHub repository URLs will reference both the username associated with the owner of the repository, as well as the repository name. For example, Open-Source-Contributors-JSS is the owner of the hacktoberfest repository, so the GitHub URL for this project is: 

<a href="https://github.com/Open-Source-Contributors-JSS/Hacktoberfest2019">https://github.com/Open-Source-Contributors-JSS/Hacktoberfest2019</a>

###### When you’re on the main page for the repository, you’ll see a button to "Star" and “Fork” the repository on your upper right-hand side of the page, underneath your user icon.

### 3. Clone the Repository

###### To make your own local copy of the repository you would like to contribute to, let’s first open up a terminal window.

###### We’ll use the `git clone`  command along with the URL that points to your fork of the repository.

###### This URL will be similar to the URL above, except now it will end with `.git.` In the example above, the URL will look like this:
https://github.com/your-username/Hacktoberfest2019.git

###### You can alternatively copy the URL by using the green “Clone or download” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL:

![clone](https://user-images.githubusercontent.com/42115530/65821242-abda9200-e250-11e9-9aa6-803a00b3d95f.jpeg)

###### Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

`git clone https://github.com/your-username/Hacktoberfest2019.git`

![git 1](https://user-images.githubusercontent.com/42115530/65821267-f22ff100-e250-11e9-9f1e-813227cdd890.JPG)


### 4. Create a New Branch

###### To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to change into that directory.

#####    ` cd Hacktoberfest`

![git 2](https://user-images.githubusercontent.com/42115530/65821270-07a51b00-e251-11e9-9b0b-5103ef3e7fe6.JPG)

###### Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.

##### `git branch new-branch`

###### Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### ` git checkout new-branch `

![git 3](https://user-images.githubusercontent.com/42115530/65821271-0a077500-e251-11e9-872f-77b926c65660.JPG)

###### Once you enter the git `checkout` command, you will receive the following output:

######  `Output:` 
#####  `Switched to branch 'new-branch' `

 
###### At this point, you can now modify existing files or add new files to the project on your own branch.

#### Make Changes Locally. Find the js folder, click on json files and open <pre>git-commands.json</pre> and add your favorite git command alongwith a two-three lines short description in the json file.
###### Remember, json files follow a certain format, do not forget to add a comma before you start editing your block and it's good if you append a comma after finishing your block.

![git 4](https://user-images.githubusercontent.com/42115530/65821272-0d026580-e251-11e9-927a-82703f921a74.JPG)

###### Once you have modified existing files or added new files to the project, you can add them to your local repository, which you can do with the git add command. Let’s add the -A flag to add all changes that we have made:

##### ` git add -A ` or ` git add . `

![git 5](https://user-images.githubusercontent.com/42115530/65821274-0ffd5600-e251-11e9-864b-273efbbfedeb.JPG)

###### Next, we’ll want to record the changes that we made to the repository with the git commit command.

![git 6](https://user-images.githubusercontent.com/42115530/65821277-125fb000-e251-11e9-898a-42aa9c920416.JPG)

###### The commit message is an important aspect of your code contribution; it helps the other contributors fully understand the change you have made, why you made it, and how significant it is. Additionally, commit messages provide a historical record of the changes for the project at large, helping future contributors along the way.
Thus, you must ensure that you write a meaningful commit message. If in a confusion, refer to the good contribution guidelines included in the <pre>contributing.md</pre>


###### If you have a very short message, you can record that with the -m flag and the message in quotes:

###### ` Example: ` 
##### ` git commit -m "Updated Readme.md" `



###### At this point you can use the git push command to push the changes to the current branch of your forked repository:
###### ` Example:`
##### ` git push --set-upstream origin new-branch `

![git 7](https://user-images.githubusercontent.com/42115530/65821278-14c20a00-e251-11e9-922b-b8f0df45486b.JPG)



### 5. Update Local Repository

###### While working on a project alongside other contributors, it is important for you to keep your local repository up-to-date with the project as you don’t want to make a pull request for code that will cause conflicts. To keep your local copy of the code base updated, you’ll need to sync changes.

###### We’ll first go over configuring a remote for the fork, then syncing the fork.

### 6. Configure a Remote for the Fork

###### Next, you’ll have to specify a new remote upstream repository for us to sync with the fork. This will be the original repository that you forked from. you’ll have to do this with the git remote add command.

##### ` git remote add upstream https://github.com/acmbvp/Hacktoberfest.git `




###### In this example, // upstream // is the shortname we have supplied for the remote repository since in terms of Git, “upstream” refers to the repository that you cloned from. If you want to add a remote pointer to the repository of a collaborator, you may want to provide that collaborator’s username or a shortened nickname for the shortname.

### 7. Sync the Fork

###### Once you have configured a remote that references the upstream and original repository on GitHub, you are ready to sync your fork of the repository to keep it up-to-date.
###### To sync your fork, from the directory of your local repository in a terminal window, you’ll have to use the // git fetch // command to fetch the branches along with their respective commits from the upstream repository. Since you used the shortname “upstream” to refer to the upstream repository, you’ll have to pass that to the command:

##### ` git fetch upstream `

###### Switch to the local master branch of our repository:

##### ` git checkout master `

###### Now merge any changes that were made in the original repository’s master branch, that you will access through your local upstream/master branch, with your local master branch:

##### ` git merge upstream/master `

### 8. Create Pull Request

###### At this point, you are ready to make a pull request to the original repository.

###### Now navigate to your forked repository, and press the “New pull request” button on your left-hand side of the page.

# Hurray!!! You just got closer to completing your hacktoberfest challenge.

> Open Source Contributors JSS &copy; 2019
