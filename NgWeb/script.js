var name_input = document.getElementById('person-name')
var male_input = document.getElementById('male-input')
var female_input = document.getElementById('female-input')
var gender_label = document.getElementById('gender-label')
var trueness_label = document.getElementById('trueness-label')
var saved_gender = document.getElementById('saved-gender')

var myLocalStorage = window.localStorage

var his_name
var resultData
var resultObject
var should_wait = false

function guess_gender(name) {
    fetch('https://api.genderize.io?name=' + name)
        .then(res => {
            resultObject = res
            return res.json()
        })
        .then(data => {
            resultData = data
            his_name = name
            // console.log(data)    
        })
        .catch(err => console.log(err))
        .then(() => {
            if (resultObject.status == 200) {
                console.log('updating prediction box')
                gender_label.innerHTML = 'Gender: ' + resultData.gender
                trueness_label.innerHTML = 'Trueness: ' + resultData.probability
            }

            if (resultObject.status > 400) {
                alert(resultObject.statusText);
            }
            should_wait = false
        })
}

function submit() {
    if (should_wait == true) return alert('Please wait for the response')
    if (resultData == undefined) guess_gender(name_input.value)

    if (male_input.checked) {
        resultData.gender = 'male'
    }
    
    if (female_input.checked) {
        resultData.gender = 'female'
    }
        
    if (resultObject.status < 400) {

        if (!male_input.checked && !female_input.checked) {
            saved_gender.innerHTML = resultData.name
        }

        myLocalStorage.setItem('gender', resultData.gender);
        myLocalStorage.setItem('name', his_name);
        myLocalStorage.setItem('probability', resultData.probability);
    }

    start_app();
}

function clear_all() {
    console.log('clearing the storage')
    myLocalStorage.clear()
    location.reload();
}

var typingTimer; 
var doneTypingInterval = 1000;

// Event for typing keyup
name_input.addEventListener('keyup', () => {
    should_wait = true
    clearTimeout(typingTimer);
    if (name_input.value) {
        typingTimer = setTimeout(doneTyping, doneTypingInterval);
    }
});

function doneTyping () {
    guess_gender(name_input.value)
}

function start_app() {
    console.log('initializing')
    if (myLocalStorage.getItem('gender')) {
        saved_gender.innerHTML = 'Gender: ' + myLocalStorage.getItem('gender')
        // trueness_label.innerHTML = 'Trueness: ' + myLocalStorage.getItem('probability')
    }
    if (myLocalStorage.getItem('name')) {
        name_input.value = myLocalStorage.getItem('name')
    }
}

start_app()
