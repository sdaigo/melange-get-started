type sandwich =
  | Portabello
  | Ham
  | Unicorn;

type t =
  | Sandwich(sandwich)
  | Burger
  | Hotdog;

// toPrice : return the price for the given item
let toPrice =
  fun
  | Sandwich(Portabello | Ham) => 10.
  | Sandwich(Unicorn) => 80.
  | Burger => 15.
  | Hotdog => 5.;

/* toEmoji : return the emoji for the given item */
let toEmoji =
  fun
  | Sandwich(sandwich) => {
      let emoji =
        switch (sandwich) {
        | Portabello => {js|🍄|js}
        | Ham => {js|🐷|js}
        | Unicorn => {js|🦄|js}
        };
      {j|🥪($emoji)|j};
    }
  | Burger => {js|🍔|js}
  | Hotdog => {js|🌭|js};

[@react.component]
let make = (~item: t) => {
  <tr className="item">
    <td className="emoji"> {item |> toEmoji |> React.string} </td>
    <td className="price">
      {item |> toPrice |> Format.currency |> React.string}
    </td>
  </tr>;
};
