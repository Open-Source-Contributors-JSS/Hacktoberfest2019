from flask import Flask, request, redirect, render_template
app = Flask(__name__)

@app.route('/')
def index():
  return render_template("index.html")

@app.route("/form", methods=['GET', 'POST'])
def form():
  if request.method == 'POST':
    fname = request.form['fname']
    lname = request.form['lname']
    return f"Your full name is {fname} {lname}"
  else:
    return redirect("/")

app.run(host='0.0.0.0', port=8080)
