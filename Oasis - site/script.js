document.addEventListener("DOMContentLoaded", function () {
  // Seleciona todos os links que começam com #
  const links = document.querySelectorAll('a[href^="#"]');

  for (const link of links) {
    link.addEventListener("click", function (e) {
      e.preventDefault();

      const targetId = this.getAttribute("href").substring(1);
      const targetSection = document.getElementById(targetId);

      if (targetSection) {
        window.scrollTo({
          top: targetSection.offsetTop - 70, // -70px para compensar a navbar fixa
          behavior: "smooth",
        });
      }
    });
  }
});

function author_card(nome, link_github, link_linkedin, url) {
  return `
    <div class="authors-grid">
        <div class="author-card">
            <div class="avatar" style="background-image: url('/${url}');"></div>
            <h4>${nome}</h4>
            <div class="links">
                <a href="${link_github}" target="_blank">GitHub</a> | 
                <a href="${link_linkedin}" target="_blank">LinkedIn</a>
            </div>
        </div>
    </div>
    `;
}

const data = [
  {
    nome: "Abraão Santos",
    github: "https://github.com/abraaosantosdeveloper/",
    linkedin: "https://linkedin.com/in/abraaosantosdev/",
    url_img: "./abraao.jpg"
  },
  {
    nome: "Dilvanir Aline",
    github: "https://github.com/line-byte",
    linkedin: "https://www.linkedin.com/in/dilvanir-aline-alves-cabral-de-melo-393999380/",
    url_img: "./Aline.jpg"
  },
  {
    nome: "Emanoel Alesandro",
    github: "https://github.com/Emanoel0106",
    linkedin: "https://linkedin.com/in/abraaosantosdev/",
    url_img: "./emanoel.jpg"
  },
  {
    nome: "Márcio Aureliano",
    github: "https://github.com/maps-droid",
    linkedin: "https://www.linkedin.com/in/marcio-brarranco-68965312b?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app",
    url_img: "./marcio.jpg"
  },
  {
    nome: "Maria Larysse",
    github: " https://github.com/mlylp",
    linkedin: "https://www.linkedin.com/in/maria-larysse-lira-8b1a462b3/",
    url_img: "./larysse.jpg"
  },
  {
    nome: "Pedro Pessôa",
    github: "https://github.com/Ppan-droid",
    linkedin: "https://www.linkedin.com/in/pedro-pess%C3%B4a-2a4b95364?trk=contact-info",
    url_img: "./pedro.jpg"
  }
];

const secao_autores = document.getElementById("autores-lista");

secao_autores.innerHTML = "";

data.forEach(author => (secao_autores.innerHTML += author_card(author.nome, author.github, author.linkedin, author.url_img)))