[@react.component]
let make = () => {
  let (counter, setCounter) = React.useState(() => 0);

  let counterString = counter |> Int.to_string |> React.string;

  <div
    style={ReactDOMStyle.make(
      ~padding="1rem",
      ~display="flex",
      ~gridGap="1rem",
      (),
    )}>
    <button onClick={_evt => setCounter(v => v - 1)}>
      {React.string("Decrement")}
    </button>
    <p> counterString </p>
    <button onClick={_evt => setCounter(v => v + 1)}>
      {React.string("Increment")}
    </button>
  </div>;
};
