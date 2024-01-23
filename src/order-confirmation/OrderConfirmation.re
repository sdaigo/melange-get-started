[@react.component]
let make = () => {
  let items: Order.t = [|Sandwich(Ham), Burger, Sandwich(Unicorn)|];

  <div>
    <h1> {React.string("Order Confirmation")} </h1>
    <Order items />
  </div>;
};
