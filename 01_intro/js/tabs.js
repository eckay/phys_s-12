function changeIdea() {
    let selectedButton = [...document.querySelectorAll('.idea-select:checked')].map((d) => d.id)[0];
    let selectIdea = document.getElementById("project-idea");
    if (selectedButton === "automaton") {
      selectIdea.innerHTML = `
    <p class = "margin">
      I think the combination of sort-of-weird doll parts and machinery would make a drawing automaton fun to build. The old ones I've seen use cams to store data, 
      but because of the requirements for the final project, I'd be interested in trying to make one that would be programmable using a computer rather than cams. Ideally, I'd like 
      it to be capable of drawing most text and simple images. It would be cool if it could switch the drawing implement itself so it could use multiple colors of ink/pencil, but I'm not sure if that would
      be too complicated. At minimum, I'd want it to look like a decorative figure and to be able to draw a preset image. The YouTube videos are examples of a couple historical drawing automata and one recent one.
    </p>
    <div class="row">
      <div class="col-md-4">
        <iframe class="yt-vid" src="https://www.youtube-nocookie.com/embed/7ZiH7oF3OMM?si=gqQ2irdJZEgoqcOS" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
      </div>
      <div class="col-md-4">
        <iframe class="yt-vid" src="https://www.youtube-nocookie.com/embed/IeTOqDb-86s?si=H0X7oRqRlYPrXq5F&amp;start=40" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
      </div>
      <div class="col-md-4">
        <iframe class="yt-vid" src="https://www.youtube-nocookie.com/embed/FQM9JzHbCdw?si=qp1XXILfXFT0IPli" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
      </div>
    </div>`;
    }
    else {
      selectIdea.innerHTML = `
  <p class = "margin">
    My second idea is a sort of arm that could be attached to our cat's favorite toy (which looks like a fishing rod) and
    move it vertically and horizontally in a variety of patterns. He's a somewhat large cat (17 lbs), so it would have to be able
    to withstand a decent amount of pulling in addition to not pulling too hard on the toy itself. Ideally, the cat would be able to 
    activate it on his own (maybe by stepping on a button?). 
  </p>
  <div class="row">
    <div class="col-md-6 d-flex justify-content-center">
      <img width="80%" src="cat.jpg">
    </div>
    <div class="col-md-6 d-flex justify-content-center">
      <img width="80%" src="toy-idea.jpg">
    </div>
  </div>`;
    }
  }